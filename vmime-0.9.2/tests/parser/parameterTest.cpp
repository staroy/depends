//
// VMime library (http://www.vmime.org)
// Copyright (C) 2002-2013 Vincent Richard <vincent@vmime.org>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Linking this library statically or dynamically with other modules is making
// a combined work based on this library.  Thus, the terms and conditions of
// the GNU General Public License cover the whole combination.
//

#include "tests/testUtils.hpp"

#include <locale>
#include <clocale>


VMIME_TEST_SUITE_BEGIN(parameterTest)

	VMIME_TEST_LIST_BEGIN
		VMIME_TEST(testParse)
		VMIME_TEST(testParseRFC2231)
		VMIME_TEST(testGenerate)
		VMIME_TEST(testGetGeneratedSize)
		VMIME_TEST(testGenerateRFC2231)
		VMIME_TEST(testGetGeneratedSizeRFC2231)
		VMIME_TEST(testNonStandardEncodedParam)
		VMIME_TEST(testParseNonSignificantWS)
		VMIME_TEST(testEncodeTSpecials)
		VMIME_TEST(testEncodeTSpecialsInRFC2231)
		VMIME_TEST(testWhitespaceBreaksTheValue)
	VMIME_TEST_LIST_END


	// HACK: parameterizedHeaderField constructor is private
	class parameterizedHeaderField : public vmime::parameterizedHeaderField
	{
	public:

		parameterizedHeaderField()
		{
			setName("F");
			setValue(vmime::headerFieldFactory::getInstance()->createValue(getName()));
			setValue(vmime::word("X"));
		}

		using vmime::parameterizedHeaderField::generate;

		const vmime::string generate
			(const vmime::generationContext::EncodedParameterValueModes genMode,
			 const vmime::size_t maxLineLength = 0) const
		{
			vmime::generationContext ctx(vmime::generationContext::getDefaultContext());
			ctx.setEncodedParameterValueMode(genMode);

			if (maxLineLength != 0)
				ctx.setMaxLineLength(maxLineLength);

			std::ostringstream oss;
			vmime::utility::outputStreamAdapter adapter(oss);

			vmime::parameterizedHeaderField::generate(ctx, adapter);

			return oss.str();
		}
	};


	const vmime::string generateParameter
		(const vmime::parameter& param,
		 const vmime::generationContext& ctx,
		 const vmime::size_t maxLineLength = 0) const
	{
		vmime::generationContext ctx2(ctx);

		if (maxLineLength != 0)
			ctx2.setMaxLineLength(maxLineLength);

		std::ostringstream oss;
		vmime::utility::outputStreamAdapter adapter(oss);

		param.generate(ctx2, adapter);

		return oss.str();
	}


#define FIELD_VALUE(f) (f.getValue()->generate())
#define PARAM_VALUE(p, n) (p.getParameterAt(n)->getValue().generate())
#define PARAM_NAME(p, n) (p.getParameterAt(n)->getName())
#define PARAM_CHARSET(p, n) \
	(p.getParameterAt(n)->getValue().getCharset().generate())
#define PARAM_LANG(p, n) \
	(p.getParameterAt(n)->getValue().getLanguage())
#define PARAM_BUFFER(p, n) \
	(p.getParameterAt(n)->getValue().getBuffer())


	void setUp()
	{
		// Set the global C and C++ locale to the user-configured locale.
		// The locale should use UTF-8 encoding for these tests to run successfully.
		try
		{
			std::locale::global(std::locale(""));
		}
		catch (std::exception &)
		{
			std::setlocale(LC_ALL, "");
		}
	}

	void tearDown()
	{
		// Restore default locale
		std::locale::global(std::locale("C"));
	}


	void testParse()
	{
		// Simple parameter
		parameterizedHeaderField p1;
		p1.parse("X; param1=value1;\r\n");

		VASSERT_EQ("1.1", 1, p1.getParameterCount());
		VASSERT_EQ("1.2", "param1", PARAM_NAME(p1, 0));
		VASSERT_EQ("1.3", "value1", PARAM_VALUE(p1, 0));

		// Multi-section parameters (1/2)
		parameterizedHeaderField p2a;
		p2a.parse("X; param1=value1;\r\n"
			  "  param2*0=\"val\";\r\n"
			  "  param2*1=\"ue2\";");

		VASSERT_EQ("2a.1", 2, p2a.getParameterCount());
		VASSERT_EQ("2a.2", "param1", PARAM_NAME(p2a, 0));
		VASSERT_EQ("2a.3", "value1", PARAM_VALUE(p2a, 0));
		VASSERT_EQ("2a.4", "param2", PARAM_NAME(p2a, 1));
		VASSERT_EQ("2a.5", "value2", PARAM_VALUE(p2a, 1));

		// Multi-section parameters (2/2)
		parameterizedHeaderField p2b;
		p2b.parse("X; param1=value1;\r\n"
			  "  param2=\"should be ignored\";\r\n"
			  "  param2*0=\"val\";\r\n"
			  "  param2*1=\"ue2\";");

		VASSERT_EQ("2b.1", 2, p2b.getParameterCount());
		VASSERT_EQ("2b.2", "param1", PARAM_NAME(p2b, 0));
		VASSERT_EQ("2b.3", "value1", PARAM_VALUE(p2b, 0));
		VASSERT_EQ("2b.4", "param2", PARAM_NAME(p2b, 1));
		VASSERT_EQ("2b.5", "value2", PARAM_VALUE(p2b, 1));

		// Extended parameter (charset and language information)
		parameterizedHeaderField p3;
		p3.parse("X; param1*=charset'language'value1;\r\n");

		VASSERT_EQ("3.1", 1, p3.getParameterCount());
		VASSERT_EQ("3.2", "param1", PARAM_NAME(p3, 0));
		VASSERT_EQ("3.3", "charset", PARAM_CHARSET(p3, 0));
		VASSERT_EQ("3.4", "value1", PARAM_BUFFER(p3, 0));

		// Encoded characters in extended parameter values
		parameterizedHeaderField p4;
		p4.parse("X; param1*=a%20value%20with%20multiple%20word%73");  // 0x73 = 's'

		VASSERT_EQ("4.1", 1, p4.getParameterCount());
		VASSERT_EQ("4.2", "param1", PARAM_NAME(p4, 0));
		VASSERT_EQ("4.3", "a value with multiple words", PARAM_VALUE(p4, 0));

		// Invalid encoded character
		parameterizedHeaderField p5;
		p5.parse("X; param1*=test%20value%");

		VASSERT_EQ("5.1", 1, p5.getParameterCount());
		VASSERT_EQ("5.2", "param1", PARAM_NAME(p5, 0));
		VASSERT_EQ("5.3", "test value%", PARAM_VALUE(p5, 0));

		// Spaces before and after '='
		parameterizedHeaderField p6;
		p6.parse("X; param1\t=  \"value1\"");

		VASSERT_EQ("6.1", 1, p6.getParameterCount());
		VASSERT_EQ("6.2", "param1", PARAM_NAME(p6, 0));
		VASSERT_EQ("6.3", "value1", PARAM_VALUE(p6, 0));

		// Quoted strings and escaped chars
		parameterizedHeaderField p7;
		p7.parse("X; param1=\"this is a slash: \\\"\\\\\\\"\"");  // \"\\\"

		VASSERT_EQ("7.1", 1, p7.getParameterCount());
		VASSERT_EQ("7.2", "param1", PARAM_NAME(p7, 0));
		VASSERT_EQ("7.3", "this is a slash: \"\\\"", PARAM_VALUE(p7, 0));
	}

	void testParseRFC2231()
	{
		// Extended parameter with charset specified in more than one
		// section (this is forbidden by RFC, but is should not fail)
		parameterizedHeaderField p1;
		p1.parse("X; param1*0*=charset1'language1'value1;\r\n"
			   "   param1*1*=charset2'language2'value2;");

		VASSERT_EQ("1.1", 1, p1.getParameterCount());
		VASSERT_EQ("1.2", "param1", PARAM_NAME(p1, 0));
		VASSERT_EQ("1.3", "charset1", PARAM_CHARSET(p1, 0));
		VASSERT_EQ("1.4", "value1charset2'language2'value2", PARAM_BUFFER(p1, 0));

		// Charset not specified in the first section (that is not encoded),
		// but specified in the second one (legal)
		parameterizedHeaderField p2;
		p2.parse("X; param1*0=value1;\r\n"
			   "   param1*1*=charset'language'value2;");

		VASSERT_EQ("2.1", 1, p2.getParameterCount());
		VASSERT_EQ("2.2", "param1", PARAM_NAME(p2, 0));
		VASSERT_EQ("2.3", "charset", PARAM_CHARSET(p2, 0));
		VASSERT_EQ("2.4", "value1value2", PARAM_BUFFER(p2, 0));

		// Characters prefixed with '%' in a simple (not extended) section
		// should not be decoded
		parameterizedHeaderField p3;
		p3.parse("X; param1=val%20ue1");

		VASSERT_EQ("3.1", 1, p3.getParameterCount());
		VASSERT_EQ("3.2", "param1", PARAM_NAME(p3, 0));
		VASSERT_EQ("3.3", "val%20ue1", PARAM_VALUE(p3, 0));

		// Multiple sections + charset specified and encoding
		parameterizedHeaderField p4;
		p4.parse("X; param1*0*=charset'language'value1a%20;"
			   "   param1*1*=value1b%20;"
			   "   param1*2=value1c");

		VASSERT_EQ("4.1", 1, p4.getParameterCount());
		VASSERT_EQ("4.2", "param1", PARAM_NAME(p4, 0));
		VASSERT_EQ("4.3", "charset", PARAM_CHARSET(p4, 0));
		VASSERT_EQ("4.4", "value1a value1b value1c", PARAM_BUFFER(p4, 0));

		// No charset specified: defaults to US-ASCII
		parameterizedHeaderField p5;
		p5.parse("X; param1*='language'value1");

		VASSERT_EQ("5.1", 1, p5.getParameterCount());
		VASSERT_EQ("5.2", "param1", PARAM_NAME(p5, 0));
		VASSERT_EQ("5.3", "us-ascii", PARAM_CHARSET(p5, 0));
		VASSERT_EQ("5.4", "value1", PARAM_BUFFER(p5, 0));

		// Language specification
		parameterizedHeaderField p6;
		p6.parse("X; param1*=us-ascii'en-us'This%20is%20%2A%2A%2Afun%2A%2A%2A");

		VASSERT_EQ("6.1", 1, p6.getParameterCount());
		VASSERT_EQ("6.2", "param1", PARAM_NAME(p6, 0));
		VASSERT_EQ("6.3", "us-ascii", PARAM_CHARSET(p6, 0));
		VASSERT_EQ("6.4", "en-us", PARAM_LANG(p6, 0));
		VASSERT_EQ("6.5", "This is ***fun***", PARAM_BUFFER(p6, 0));
	}

	void testGenerate()
	{
		// Simple parameter/value
		parameterizedHeaderField p1;
		p1.appendParameter(vmime::make_shared <vmime::parameter>("param1", "value1"));

		VASSERT_EQ("1", "F: X; param1=value1", p1.generate());

		// Value that needs quoting (1/2)
		parameterizedHeaderField p2a;
		p2a.appendParameter(vmime::make_shared <vmime::parameter>("param1", "value1a;value1b"));

		VASSERT_EQ("2a", "F: X; param1=\"value1a;value1b\"", p2a.generate());

		// Value that needs quoting (2/2)
		parameterizedHeaderField p2b;
		p2b.appendParameter(vmime::make_shared <vmime::parameter>("param1", "va\\lue\"1"));

		VASSERT_EQ("2b", "F: X; param1=\"va\\\\lue\\\"1\"", p2b.generate());
	}

	void testGetGeneratedSize()
	{
		vmime::generationContext ctx(vmime::generationContext::getDefaultContext());

		vmime::parameter p1("param1", "value1");
		VASSERT("1", p1.getGeneratedSize(ctx) >= generateParameter(p1, ctx).length());

		vmime::parameter p2a("param1", "value1a;value1b");
		VASSERT("2&", p2a.getGeneratedSize(ctx) >= generateParameter(p2a, ctx).length());

		vmime::parameter p2b("param1", "va\\lue\"1");
		VASSERT("1", p2b.getGeneratedSize(ctx) >= generateParameter(p2b, ctx).length());
	}

	void testGenerateRFC2231()
	{
		// Extended parameter with charset specifier
		parameterizedHeaderField p1;
		p1.appendParameter(vmime::make_shared <vmime::parameter>("param1",
			vmime::word("value 1\xe9", vmime::charset("charset"))));

		VASSERT_EQ("1.no-encoding", "F: X; param1=\"value 1\"",
			p1.generate(vmime::generationContext::PARAMETER_VALUE_NO_ENCODING));

		VASSERT_EQ("1.rfc2047", "F: X; param1=\"=?charset?Q?value_1=E9?=\"",
			p1.generate(vmime::generationContext::PARAMETER_VALUE_RFC2047_ONLY));

		VASSERT_EQ("1.rfc2231", "F: X; param1*=charset''value%201%E9",
			p1.generate(vmime::generationContext::PARAMETER_VALUE_RFC2231_ONLY));

		VASSERT_EQ("1.both", "F: X; param1=\"=?charset?Q?value_1=E9?=\";param1*=charset''value%201%E9",
			p1.generate(vmime::generationContext::PARAMETER_VALUE_RFC2231_AND_RFC2047));

		// Value that spans on multiple lines
		parameterizedHeaderField p2;
		p2.appendParameter(vmime::make_shared <vmime::parameter>("param1",
			vmime::word("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
				    vmime::charset("charset"))));

		VASSERT_EQ("2.no-encoding", "F: X; \r\n "
			"param1=abcdefghijkl",
			p2.generate(vmime::generationContext::PARAMETER_VALUE_NO_ENCODING, 25));  // max line length = 25

		VASSERT_EQ("2.rfc2047", "F: X; \r\n "
			"param1=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
			p2.generate(vmime::generationContext::PARAMETER_VALUE_RFC2047_ONLY, 25));  // max line length = 25

		VASSERT_EQ("2.rfc2231", "F: X; \r\n "
			"param1*0*=charset''abc;\r\n "
			"param1*1*=defghijkl;\r\n "
			"param1*2*=mnopqrstu;\r\n "
			"param1*3*=vwxyzABCD;\r\n "
			"param1*4*=EFGHIJKLM;\r\n "
			"param1*5*=NOPQRSTUV;\r\n "
			"param1*6*=WXYZ",
			p2.generate(vmime::generationContext::PARAMETER_VALUE_RFC2231_ONLY, 25));  // max line length = 25

		VASSERT_EQ("2.both", "F: X; \r\n "
			"param1=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ;\r\n "
			"param1*0*=charset''abc;\r\n "
			"param1*1*=defghijkl;\r\n "
			"param1*2*=mnopqrstu;\r\n "
			"param1*3*=vwxyzABCD;\r\n "
			"param1*4*=EFGHIJKLM;\r\n "
			"param1*5*=NOPQRSTUV;\r\n "
			"param1*6*=WXYZ",
			p2.generate(vmime::generationContext::PARAMETER_VALUE_RFC2231_AND_RFC2047, 25));  // max line length = 25

		// Non-ASCII parameter value
		parameterizedHeaderField p3;
		p3.appendParameter(vmime::make_shared <vmime::parameter>("param1",
			vmime::word("?????????????????????????????????????????????????? ?????????????????????????????????? ?????????????????? ?????????????????? ?????????????????? ???????????????????? 2008.doc",
				vmime::charset("utf-8"))));

		VASSERT_EQ("3.no-encoding", "F: X; \r\n "
			"param1=\"      2008.doc\"",
			p3.generate(vmime::generationContext::PARAMETER_VALUE_NO_ENCODING, 80));  // max line length = 80

		VASSERT_EQ("3.7bit-only", "F: X; \r\n "
			"param1=\"=?utf-8?B?zrTPg8+Dz4PPg8+Dz4PPg8+Dz4PPg8+Dz4PPg8+Dz4PPg8+Dz4PPg8+DzrTPg860?=\r\n "
			"=?utf-8?B?zrEgzrTPg86xzrTPg860z4POsc60z4POsc60zrHPg860zrHPgyDOtM+DzrHOtM6x?=\r\n "
			"=?utf-8?B?z4POtM+DzrEgzrTPg86xzrTOsc+DzrTPg86xIM60zrHPg860zrHPg860zrHPgyDOtA==?=\r\n "
			"=?utf-8?B?zrHPg86xz4fPhs60zrTPg86xIDIwMDguZG9j?=\"",
			p3.generate(vmime::generationContext::PARAMETER_VALUE_RFC2047_ONLY, 80));  // max line length = 80

		VASSERT_EQ("3.both", "F: X; \r\n "
			"param1=\"=?utf-8?B?zrTPg8+Dz4PPg8+Dz4PPg8+Dz4PPg8+Dz4PPg8+Dz4PPg8+Dz4PPg8+DzrTPg860?=\r\n "
			"=?utf-8?B?zrEgzrTPg86xzrTPg860z4POsc60z4POsc60zrHPg860zrHPgyDOtM+DzrHOtM6x?=\r\n "
			"=?utf-8?B?z4POtM+DzrEgzrTPg86xzrTOsc+DzrTPg86xIM60zrHPg860zrHPg860zrHPgyDOtA==?=\r\n "
			"=?utf-8?B?zrHPg86xz4fPhs60zrTPg86xIDIwMDguZG9j?=\";\r\n "
			"param1*0*=utf-8''%CE%B4%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83;\r\n "
			"param1*1*=%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83;\r\n "
			"param1*2*=%CE%B4%CF%83%CE%B4%CE%B1%20%CE%B4%CF%83%CE%B1%CE%B4%CF%83%CE%B4%CF;\r\n "
			"param1*3*=%83%CE%B1%CE%B4%CF%83%CE%B1%CE%B4%CE%B1%CF%83%CE%B4%CE%B1%CF%83%20;\r\n "
			"param1*4*=%CE%B4%CF%83%CE%B1%CE%B4%CE%B1%CF%83%CE%B4%CF%83%CE%B1%20%CE%B4%CF;\r\n "
			"param1*5*=%83%CE%B1%CE%B4%CE%B1%CF%83%CE%B4%CF%83%CE%B1%20%CE%B4%CE%B1%CF%83;\r\n "
			"param1*6*=%CE%B4%CE%B1%CF%83%CE%B4%CE%B1%CF%83%20%CE%B4%CE%B1%CF%83%CE%B1%CF;\r\n "
			"param1*7*=%87%CF%86%CE%B4%CE%B4%CF%83%CE%B1%202008.doc",
			p3.generate(vmime::generationContext::PARAMETER_VALUE_RFC2231_AND_RFC2047, 80));  // max line length = 80

		VASSERT_EQ("3.either", "F: X; param1*0*=utf-8''%CE%B4%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83;\r\n "
			"param1*1*=%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83%CF%83;\r\n "
			"param1*2*=%CE%B4%CF%83%CE%B4%CE%B1%20%CE%B4%CF%83%CE%B1%CE%B4%CF%83%CE%B4%CF;\r\n "
			"param1*3*=%83%CE%B1%CE%B4%CF%83%CE%B1%CE%B4%CE%B1%CF%83%CE%B4%CE%B1%CF%83%20;\r\n "
			"param1*4*=%CE%B4%CF%83%CE%B1%CE%B4%CE%B1%CF%83%CE%B4%CF%83%CE%B1%20%CE%B4%CF;\r\n "
			"param1*5*=%83%CE%B1%CE%B4%CE%B1%CF%83%CE%B4%CF%83%CE%B1%20%CE%B4%CE%B1%CF%83;\r\n "
			"param1*6*=%CE%B4%CE%B1%CF%83%CE%B4%CE%B1%CF%83%20%CE%B4%CE%B1%CF%83%CE%B1%CF;\r\n "
			"param1*7*=%87%CF%86%CE%B4%CE%B4%CF%83%CE%B1%202008.doc",
			p3.generate(vmime::generationContext::PARAMETER_VALUE_RFC2231_ONLY, 80));  // max line length = 80

		// No encoding needed
		parameterizedHeaderField p4;
		p4.appendParameter(vmime::make_shared <vmime::parameter>("param1",
			vmime::word("va lue", vmime::charset("charset"))));

		VASSERT_EQ("4.no-encoding", "F: X; param1=\"va lue\"",
			p4.generate(vmime::generationContext::PARAMETER_VALUE_NO_ENCODING));

		VASSERT_EQ("4.rfc2047", "F: X; param1=\"va lue\"",
			p4.generate(vmime::generationContext::PARAMETER_VALUE_RFC2047_ONLY));

		VASSERT_EQ("4.rfc2231", "F: X; param1=\"va lue\"",
			p4.generate(vmime::generationContext::PARAMETER_VALUE_RFC2231_ONLY));

		VASSERT_EQ("4.both", "F: X; param1=\"va lue\"",
			p4.generate(vmime::generationContext::PARAMETER_VALUE_RFC2231_AND_RFC2047));

		// Language specification
		parameterizedHeaderField p5;
		p5.appendParameter(vmime::make_shared <vmime::parameter>("param1",
			vmime::word("This is ***fun***", vmime::charset("us-ascii"), "en-us")));

		VASSERT_EQ("5.no-encoding", "F: X; param1=\"This is ***fun***\"",
			p5.generate(vmime::generationContext::PARAMETER_VALUE_NO_ENCODING));

		VASSERT_EQ("5.rfc2047", "F: X; param1=\"=?us-ascii*en-us?Q?This_is_***fun***?=\"",
			p5.generate(vmime::generationContext::PARAMETER_VALUE_RFC2047_ONLY));

		VASSERT_EQ("5.rfc2231", "F: X; param1*=us-ascii''This%20is%20***fun***",
			p5.generate(vmime::generationContext::PARAMETER_VALUE_RFC2231_ONLY));

		VASSERT_EQ("5.both", "F: X; "
				"param1=\"=?us-ascii*en-us?Q?This_is_***fun***?=\";\r\n "
				"param1*=us-ascii''This%20is%20***fun***",
			p5.generate(vmime::generationContext::PARAMETER_VALUE_RFC2231_AND_RFC2047));
	}

	void testGetGeneratedSizeRFC2231()
	{
		vmime::generationContext ctx(vmime::generationContext::getDefaultContext());

		// Extended parameter with charset specifier
		vmime::parameter p1(
			"param1",
			vmime::word("value 1\xe9", vmime::charset("charset"))
		);

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_NO_ENCODING);
		VASSERT("1.no-encoding", p1.getGeneratedSize(ctx) >= generateParameter(p1, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2047_ONLY);
		VASSERT("1.rfc2047", p1.getGeneratedSize(ctx) >= generateParameter(p1, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2231_ONLY);
		VASSERT("1.rfc2231", p1.getGeneratedSize(ctx) >= generateParameter(p1, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2231_AND_RFC2047);
		VASSERT("1.both", p1.getGeneratedSize(ctx) >= generateParameter(p1, ctx).length());

		// Value that spans on multiple lines
		vmime::parameter p2(
			"param1",
			vmime::word(
				"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
				vmime::charset("charset")
			)
		);

		ctx.setMaxLineLength(25);
		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_NO_ENCODING);
		VASSERT("2.no-encoding", p2.getGeneratedSize(ctx) >= generateParameter(p2, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2047_ONLY);
		VASSERT("2.rfc2047", p2.getGeneratedSize(ctx) >= generateParameter(p2, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2231_ONLY);
		VASSERT("2.rfc2231", p2.getGeneratedSize(ctx) >= generateParameter(p2, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2231_AND_RFC2047);
		VASSERT("2.both", p2.getGeneratedSize(ctx) >= generateParameter(p2, ctx).length());

		// Non-ASCII parameter value
		vmime::parameter p3(
			"param1",
			vmime::word(
				"?????????????????????????????????????????????????? ?????????????????????????????????? ?????????????????? ?????????????????? ?????????????????? ???????????????????? 2008.doc",
				vmime::charset("utf-8")
			)
		);

		ctx.setMaxLineLength(vmime::generationContext::getDefaultContext().getMaxLineLength());
		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_NO_ENCODING);
		VASSERT("3.no-encoding", p3.getGeneratedSize(ctx) >= generateParameter(p3, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2047_ONLY);
		VASSERT("3.rfc2047", p3.getGeneratedSize(ctx) >= generateParameter(p3, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2231_ONLY);
		VASSERT("3.rfc2231", p3.getGeneratedSize(ctx) >= generateParameter(p3, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2231_AND_RFC2047);
		VASSERT("3.both", p3.getGeneratedSize(ctx) >= generateParameter(p3, ctx).length());

		// No encoding needed
		vmime::parameter p4(
			"param1",
			vmime::word("va lue", vmime::charset("charset"))
		);

		ctx.setMaxLineLength(vmime::generationContext::getDefaultContext().getMaxLineLength());
		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_NO_ENCODING);
		VASSERT("4.no-encoding", p4.getGeneratedSize(ctx) >= generateParameter(p4, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2047_ONLY);
		VASSERT("4.rfc2047", p4.getGeneratedSize(ctx) >= generateParameter(p4, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2231_ONLY);
		VASSERT("4.rfc2231", p4.getGeneratedSize(ctx) >= generateParameter(p4, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2231_AND_RFC2047);
		VASSERT("4.both", p4.getGeneratedSize(ctx) >= generateParameter(p4, ctx).length());

		// Language specification
		vmime::parameter p5(
			"param1",
			vmime::word("This is ***fun***", vmime::charset("us-ascii"), "en-us")
		);

		ctx.setMaxLineLength(vmime::generationContext::getDefaultContext().getMaxLineLength());
		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_NO_ENCODING);
		VASSERT("5.no-encoding", p5.getGeneratedSize(ctx) >= generateParameter(p5, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2047_ONLY);
		VASSERT("5.rfc2047", p5.getGeneratedSize(ctx) >= generateParameter(p5, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2231_ONLY);
		VASSERT("5.rfc2231", p5.getGeneratedSize(ctx) >= generateParameter(p5, ctx).length());

		ctx.setEncodedParameterValueMode(vmime::generationContext::PARAMETER_VALUE_RFC2231_AND_RFC2047);
		VASSERT("5.both", p5.getGeneratedSize(ctx) >= generateParameter(p5, ctx).length());
	}

	void testNonStandardEncodedParam()
	{
		// This syntax is non-standard (expressly prohibited
		// by RFC-2047), but is used by Mozilla:
		//
    		// Content-Type: image/png;
		//    name="=?us-ascii?Q?Logo_VMime=2Epng?="

		parameterizedHeaderField p1;
		p1.parse("image/png; name=\"=?us-ascii?Q?Logo_VMime=2Epng?=\"");

		VASSERT_EQ("1.1", 1, p1.getParameterCount());
		VASSERT_EQ("1.2", "name", PARAM_NAME(p1, 0));
		VASSERT_EQ("1.3", "Logo VMime.png", PARAM_VALUE(p1, 0));

		parameterizedHeaderField p2;
		p2.parse("image/png; name=\"Logo =?us-ascii?Q?VMime=2Epng?=\"");

		VASSERT_EQ("2.1", 1, p2.getParameterCount());
		VASSERT_EQ("2.2", "name", PARAM_NAME(p2, 0));
		VASSERT_EQ("2.3", "Logo VMime.png", PARAM_VALUE(p2, 0));
	}

	// Parse parameters with non-significant whitespaces
	void testParseNonSignificantWS()
	{
		parameterizedHeaderField p1;
		p1.parse(" \t X   \r\n");

		VASSERT_EQ("1.1", "X", FIELD_VALUE(p1));

		parameterizedHeaderField p2;
		p2.parse(" X  ; param1 =  value1 \r\n");

		VASSERT_EQ("2.1", 1, p2.getParameterCount());
		VASSERT_EQ("2.2", "X", FIELD_VALUE(p2));
		VASSERT_EQ("2.3", "param1", PARAM_NAME(p2, 0));
		VASSERT_EQ("2.4", "value1", PARAM_VALUE(p2, 0));
	}

	// Encode "tspecials"
	void testEncodeTSpecials()
	{
		VASSERT_EQ(" 1", "p=\"val(ue\"",  vmime::make_shared <vmime::parameter>("p", "val(ue")->generate());
		VASSERT_EQ(" 2", "p=\"val)ue\"",  vmime::make_shared <vmime::parameter>("p", "val)ue")->generate());
		VASSERT_EQ(" 3", "p=\"val<ue\"",  vmime::make_shared <vmime::parameter>("p", "val<ue")->generate());
		VASSERT_EQ(" 4", "p=\"val>ue\"",  vmime::make_shared <vmime::parameter>("p", "val>ue")->generate());
		VASSERT_EQ(" 5", "p=\"val@ue\"",  vmime::make_shared <vmime::parameter>("p", "val@ue")->generate());
		VASSERT_EQ(" 6", "p=\"val,ue\"",  vmime::make_shared <vmime::parameter>("p", "val,ue")->generate());
		VASSERT_EQ(" 7", "p=\"val;ue\"",  vmime::make_shared <vmime::parameter>("p", "val;ue")->generate());
		VASSERT_EQ(" 8", "p=\"val:ue\"",  vmime::make_shared <vmime::parameter>("p", "val:ue")->generate());
		VASSERT_EQ(" 9", "p=\"val/ue\"",  vmime::make_shared <vmime::parameter>("p", "val/ue")->generate());
		VASSERT_EQ("10", "p=\"val[ue\"",  vmime::make_shared <vmime::parameter>("p", "val[ue")->generate());
		VASSERT_EQ("11", "p=\"val]ue\"",  vmime::make_shared <vmime::parameter>("p", "val]ue")->generate());
		VASSERT_EQ("12", "p=\"val?ue\"",  vmime::make_shared <vmime::parameter>("p", "val?ue")->generate());
		VASSERT_EQ("13", "p=\"val=ue\"",  vmime::make_shared <vmime::parameter>("p", "val=ue")->generate());
		VASSERT_EQ("14", "p=\"val ue\"",  vmime::make_shared <vmime::parameter>("p", "val ue")->generate());
		VASSERT_EQ("15", "p=\"val\tue\"", vmime::make_shared <vmime::parameter>("p", "val\tue")->generate());
	}

	// http://sourceforge.net/projects/vmime/forums/forum/237356/topic/3812278
	void testEncodeTSpecialsInRFC2231()
	{
		VASSERT_EQ("1", "filename*=UTF-8''my_file_name_%C3%B6%C3%A4%C3%BC_%281%29.txt",
			vmime::make_shared <vmime::parameter>
				("filename",
				 vmime::word("my_file_name_\xc3\xb6\xc3\xa4\xc3\xbc_(1).txt", "UTF-8"))->generate());
	}

	void testWhitespaceBreaksTheValue()
	{
		parameterizedHeaderField p;
		p.parse("xxx yyy; param1=value1 \r\n");

		VASSERT_EQ("count", 1, p.getParameterCount());
		VASSERT_EQ("value", "xxx", FIELD_VALUE(p));
		VASSERT_EQ("param1.name", "param1", PARAM_NAME(p, 0));
		VASSERT_EQ("param1.value", "value1", PARAM_VALUE(p, 0));
	}

VMIME_TEST_SUITE_END

