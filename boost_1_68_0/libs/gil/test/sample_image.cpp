/*
    Copyright 2005-2007 Adobe Systems Incorporated
   
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).

    See http://opensource.adobe.com/gil for most recent version including documentation.
*/

#include <boost/gil.hpp>

unsigned char halfdome[][3174]={
{
    47,47,48,48,48,48,48,47,51,50,49,51,50,60,110,150,143,93,164,168,125,137,53,54,56,54,52,50,52,51,50,51,53,52,51,51,52,53,51,51,52,52,51,51,50,52,51,53,51,52,51,53,52,54,57,57,59,57,59,59,60,60,177,185,206,221,230,224,227,
    50,52,48,51,50,51,52,51,53,51,53,53,56,54,59,59,61,64,149,149,153,65,58,57,57,57,55,55,56,57,55,57,56,56,53,54,56,55,53,55,54,56,56,55,54,54,56,54,55,57,56,54,57,57,59,70,178,75,67,191,132,194,226,201,226,226,227,237,222,
    54,54,55,54,53,54,55,54,56,58,57,59,59,59,59,61,61,61,62,64,65,65,85,61,58,59,60,61,60,61,58,60,58,60,59,60,59,58,60,60,57,59,59,58,60,61,59,57,58,60,60,62,61,63,192,210,223,223,231,222,226,218,208,204,205,206,205,215,207,
    58,57,57,59,58,58,60,58,60,60,59,58,62,63,64,64,62,63,66,66,67,67,65,66,64,62,64,61,62,63,65,64,63,63,64,60,63,63,62,64,62,64,63,65,63,64,63,62,61,64,63,84,119,69,146,179,202,221,217,208,205,209,206,212,201,182,178,184,183,
    60,61,62,60,61,64,64,62,65,63,65,66,69,65,66,67,69,67,69,69,67,70,71,70,69,69,68,68,67,70,70,69,69,68,69,67,66,68,67,75,70,67,89,65,67,67,67,66,66,67,68,78,93,159,188,178,161,185,196,215,196,187,174,172,170,174,175,171,171,
    66,66,65,66,68,69,67,68,67,70,68,70,72,72,73,73,73,73,74,75,75,75,76,74,75,75,74,75,76,75,75,74,75,75,74,75,76,90,157,157,158,177,163,182,161,72,76,70,71,71,72,74,75,80,117,129,143,166,200,194,191,210,215,200,182,181,176,182,196,
    72,72,71,72,72,71,74,72,74,73,73,77,77,78,77,79,77,80,78,79,82,80,81,92,81,91,80,80,81,81,81,79,81,79,116,123,103,96,87,80,105,115,140,82,97,97,130,169,162,124,77,78,80,79,81,83,83,142,192,202,211,182,203,191,194,176,169,184,184,
    75,76,75,73,77,77,79,76,79,77,79,80,81,84,84,83,85,86,87,166,241,96,89,88,89,88,100,88,88,87,92,203,91,173,178,162,179,87,86,85,83,84,84,82,83,82,85,83,85,94,81,83,81,83,84,135,183,187,192,176,180,208,193,216,203,196,196,207,191,
    79,80,79,81,81,82,82,86,83,84,85,88,89,95,244,238,93,128,222,227,245,248,231,99,159,98,183,196,95,97,183,215,215,223,230,230,228,117,92,90,90,90,88,87,87,86,87,87,88,86,89,89,90,91,101,231,214,189,221,165,166,192,184,193,194,176,170,159,157,
    84,84,86,86,86,88,88,88,90,90,91,94,217,244,246,248,249,188,223,223,224,231,232,222,226,218,189,171,190,199,223,179,199,204,205,202,203,205,188,101,97,93,94,93,93,95,96,106,115,97,96,98,209,234,217,224,242,242,242,217,214,191,139,183,179,179,164,154,143,
    89,89,89,92,91,91,93,95,94,96,115,226,208,212,235,241,245,212,196,200,201,209,203,192,183,187,219,192,198,211,214,224,200,197,184,181,186,203,190,218,189,131,173,189,160,188,173,175,185,197,199,201,192,237,211,196,225,241,242,230,238,222,222,221,218,188,168,184,197,
    95,98,98,98,99,101,102,161,161,143,215,193,232,200,200,204,227,208,228,214,212,226,48,195,213,193,191,203,201,206,229,232,210,183,225,221,234,232,234,197,206,189,204,200,193,201,191,200,206,215,223,202,196,186,189,181,209,211,215,183,236,232,176,209,217,231,181,177,178,
    103,101,105,106,153,171,197,209,204,218,184,169,199,197,210,213,202,209,215,222,234,203,120,41,195,197,187,197,186,208,193,198,198,196,197,200,201,198,202,210,222,190,178,198,211,232,226,220,204,189,190,199,188,194,193,170,169,187,190,209,225,219,208,225,212,207,199,191,203,
    109,109,111,150,205,175,184,193,175,161,165,121,134,130,126,160,203,190,184,161,147,204,61,89,193,201,198,185,215,192,183,193,189,209,189,174,172,172,170,178,197,188,186,214,227,229,143,163,160,182,193,207,189,209,190,191,176,184,197,171,180,181,207,218,218,212,176,170,170,
    118,182,143,213,169,184,183,192,201,179,193,212,203,182,154,196,205,163,201,193,191,117,59,45,179,193,228,204,203,186,202,189,159,162,166,180,195,195,191,218,205,177,201,200,199,204,228,183,202,209,202,203,199,212,217,189,207,183,186,192,188,188,175,177,183,179,186,179,184,
    126,155,183,185,189,188,185,197,175,183,192,192,188,151,172,86,190,196,184,178,128,111,57,56,135,192,188,198,195,150,180,202,214,224,211,205,182,197,199,195,211,196,181,194,206,194,194,194,192,211,197,198,201,191,197,194,197,192,189,186,181,177,169,190,171,163,171,175,160,
    133,134,136,136,163,146,116,166,186,181,205,201,93,132,137,198,207,190,69,119,127,110,70,66,153,192,180,164,168,179,188,199,189,177,183,188,189,160,177,190,194,193,192,194,124,175,193,186,178,180,207,209,187,178,144,97,131,159,105,200,114,125,135,141,179,199,172,108,117,
    120,151,138,128,163,112,124,96,103,139,102,149,213,197,208,214,193,80,104,154,107,125,84,63,141,161,163,175,183,186,190,183,201,79,86,204,191,207,194,207,184,169,141,146,171,181,128,125,83,91,101,114,127,163,120,119,114,122,126,140,87,115,113,125,186,104,83,68,84,
    118,133,167,92,126,109,124,173,137,181,150,147,166,203,176,178,82,81,123,109,137,146,60,56,146,193,156,175,180,175,194,203,185,178,82,84,74,113,105,65,64,127,65,70,140,92,83,82,80,80,82,79,84,74,99,138,84,76,109,77,142,123,76,83,71,74,55,54,34,
    182,127,117,134,158,163,201,189,166,149,192,147,191,164,175,165,120,174,99,109,167,130,153,62,180,131,96,193,203,204,191,215,183,141,70,70,66,68,73,73,71,61,74,85,95,66,63,133,154,135,89,113,89,102,69,124,68,85,77,56,51,72,94,34,60,37,90,39,34,
    149,167,135,154,108,173,152,148,184,153,157,182,167,194,176,161,202,148,120,132,149,174,156,125,147,74,133,220,225,187,116,218,209,216,70,69,72,68,61,59,60,63,70,73,63,64,81,59,84,99,80,95,70,90,52,76,162,144,87,67,65,68,98,116,90,55,140,156,58,
    91,120,142,143,157,191,188,196,151,209,199,189,177,188,81,77,44,102,112,126,155,70,200,127,88,107,87,59,95,101,153,145,203,188,62,129,124,63,66,58,60,62,67,58,60,68,62,63,77,64,63,64,71,130,97,92,105,72,67,71,158,166,144,152,160,127,125,140,115,
    133,164,135,143,168,172,196,181,211,206,197,165,144,56,91,59,46,57,65,157,146,89,177,128,59,53,76,59,63,58,132,122,126,183,209,68,59,74,69,74,77,76,78,49,57,57,72,64,67,81,100,69,146,137,153,69,140,166,83,173,175,169,171,166,41,149,154,120,172,
    101,131,158,153,167,86,82,193,163,204,140,129,105,111,44,46,32,157,150,190,120,52,120,163,144,71,68,84,81,87,160,160,106,123,121,97,69,75,79,70,60,57,73,60,61,61,94,77,73,131,115,126,121,96,130,169,128,128,145,180,159,64,139,106,147,45,27,33,20,
    67,80,168,201,199,68,148,210,111,132,85,63,139,88,101,60,92,96,66,104,76,47,103,165,115,82,49,89,113,88,127,168,178,133,81,90,84,60,63,105,64,80,64,67,54,62,70,89,88,57,86,129,159,154,202,146,143,126,60,57,69,66,144,32,28,33,62,27,35,
    98,101,82,151,129,73,80,129,134,102,116,66,81,53,87,110,95,87,144,69,123,118,106,95,88,69,69,108,91,151,158,132,137,71,158,179,184,145,65,72,64,91,72,73,76,65,60,52,57,63,119,73,67,128,114,80,123,134,172,158,108,114,28,27,28,22,33,27,52,
    158,127,109,79,90,75,74,169,97,94,124,61,121,160,171,150,102,60,47,115,136,121,155,81,142,141,135,114,114,144,78,118,79,76,67,123,90,125,77,148,103,77,68,96,73,68,50,62,60,98,101,113,117,117,122,143,97,51,64,60,51,28,37,44,35,30,40,52,74,
    139,174,90,111,108,143,123,135,128,113,129,123,139,132,96,55,47,57,69,95,102,76,124,76,52,59,148,131,119,68,86,152,100,105,128,89,139,116,118,131,125,151,93,66,66,61,61,61,58,65,81,68,87,88,102,96,90,111,72,71,79,29,42,37,46,44,49,61,96,
    128,159,122,75,55,64,168,129,93,116,109,122,140,149,161,48,58,55,93,96,87,122,76,74,57,66,144,143,57,61,87,130,96,115,131,54,105,117,87,89,79,168,139,156,108,106,80,60,60,87,69,101,85,72,66,90,84,91,91,101,127,41,37,65,65,48,30,70,128,
    153,175,59,54,52,155,159,113,143,118,113,127,149,121,148,81,162,97,120,140,57,51,57,58,80,56,124,164,81,58,100,140,60,112,118,98,106,93,65,89,65,129,61,144,119,182,171,78,148,70,101,91,85,90,78,106,89,109,118,131,117,54,75,100,86,47,78,181,134,
    60,50,51,52,48,148,87,156,170,141,146,159,77,51,144,174,102,112,161,49,58,73,46,63,64,63,60,135,129,122,87,121,122,174,105,79,96,55,56,60,108,39,46,67,51,144,123,136,59,91,80,99,84,62,92,101,103,99,128,136,215,127,110,139,121,74,135,181,175,
    55,51,55,54,105,173,137,149,186,92,84,79,91,92,96,190,101,164,72,50,75,51,67,56,72,93,118,53,63,57,82,159,182,150,127,53,57,69,59,58,54,62,78,71,96,132,90,72,55,63,83,119,86,131,65,66,114,140,95,130,160,135,158,124,133,94,135,147,140,
    56,64,47,127,175,145,131,132,178,110,84,71,127,64,136,118,93,86,139,66,116,79,55,64,50,80,133,72,95,161,164,163,163,106,68,52,58,40,60,42,42,84,86,110,88,129,73,72,43,49,49,84,116,93,78,76,132,110,147,126,122,132,82,139,138,79,62,175,158,
    50,53,56,59,170,124,166,103,147,89,116,125,101,126,122,156,100,151,165,128,146,54,73,143,66,128,147,149,145,139,144,162,161,109,94,55,46,85,54,57,69,47,63,59,127,65,85,44,99,71,55,70,37,87,119,109,70,122,161,145,148,179,129,119,77,129,134,160,141,
    99,53,76,140,161,77,119,137,163,68,89,92,58,138,122,153,129,88,137,134,134,99,95,116,130,117,155,120,136,108,165,158,207,58,87,77,43,55,51,119,59,43,71,63,83,61,86,45,34,72,112,59,162,56,39,66,124,132,139,201,164,172,69,75,92,89,139,150,50,
    48,49,56,85,83,51,103,106,118,87,104,190,118,110,143,154,74,144,119,103,117,109,155,141,102,104,96,134,111,89,155,154,121,66,43,42,31,41,54,53,70,52,62,47,97,102,71,57,48,42,60,77,84,72,49,62,56,121,67,173,55,203,53,95,56,54,57,103,57,
    48,55,119,169,97,101,106,123,84,55,144,135,116,143,84,114,116,148,102,128,104,114,109,65,93,104,106,164,128,128,145,185,115,51,135,165,75,70,112,152,108,92,57,55,60,59,54,57,120,86,69,136,110,132,62,73,78,88,72,94,57,92,168,55,107,53,43,50,28,
    51,51,66,75,71,56,127,117,50,100,145,138,100,128,73,158,105,112,112,170,102,66,92,107,144,140,142,146,147,167,140,116,135,126,175,126,75,118,95,115,62,117,105,70,80,46,75,105,121,127,112,56,89,101,109,52,102,53,51,81,55,157,144,130,47,42,63,82,47,
    76,57,122,66,98,54,48,82,65,133,111,135,108,92,146,48,147,123,146,103,102,94,140,100,90,112,100,146,148,151,171,117,160,114,135,128,95,121,129,105,83,128,135,82,118,91,81,60,102,121,107,97,89,117,93,51,52,35,72,48,59,55,57,41,38,56,60,7,24,
    97,144,102,119,53,129,63,74,104,145,134,70,109,108,131,103,86,106,108,67,115,92,127,109,66,81,160,128,165,177,120,123,157,78,114,95,149,161,102,135,94,115,129,127,108,66,64,100,84,156,127,67,89,128,88,123,38,35,42,41,50,58,47,57,134,130,111,68,68,
    115,121,134,46,126,62,107,158,98,79,113,72,82,147,149,109,117,120,103,109,127,109,130,119,92,103,175,143,124,140,110,111,57,110,124,103,128,142,122,83,109,94,152,92,105,101,46,86,88,131,160,88,108,89,88,156,128,66,59,56,69,83,71,100,76,106,116,43,28,
    118,115,62,176,98,129,95,67,62,60,88,77,90,100,113,71,83,141,88,124,124,130,102,125,103,139,109,117,179,128,54,75,102,65,158,117,124,60,112,54,71,168,127,62,145,62,107,87,98,90,136,79,130,147,126,113,69,60,116,50,78,84,80,80,57,132,117,34,101,
    126,86,127,113,141,148,92,74,81,58,60,62,118,118,49,68,152,116,125,170,119,115,148,125,119,53,87,156,78,145,71,134,52,105,101,80,50,54,93,49,124,107,107,101,55,64,72,113,64,105,133,143,93,137,157,118,70,29,61,76,60,78,105,59,48,53,42,123,70,
    45,49,104,155,135,81,157,85,73,139,91,63,99,116,84,107,59,60,144,108,69,122,128,120,144,65,96,116,121,136,152,120,91,130,144,104,63,51,64,104,78,148,78,50,53,59,64,110,75,97,133,162,85,105,146,48,118,110,88,95,52,58,59,74,42,44,7,61,67,
    47,49,75,70,86,99,80,63,174,60,94,121,66,87,115,31,50,111,118,97,101,101,121,110,128,97,131,168,125,134,155,79,150,134,103,68,97,59,86,105,125,140,124,113,40,50,53,82,72,84,104,120,154,162,42,61,35,77,60,42,103,78,58,107,52,52,8,28,59,
    49,44,44,40,69,203,93,106,97,105,98,131,68,112,131,112,119,153,80,88,94,108,126,151,133,115,153,124,141,147,115,88,116,62,132,112,133,69,66,130,151,163,66,58,82,92,73,57,103,115,95,156,118,158,62,65,51,93,32,88,55,103,100,120,81,47,66,29,38,
},
{
    93,93,93,93,93,94,94,94,93,94,95,94,95,100,129,161,158,123,175,178,145,151,98,96,96,96,96,97,95,96,96,95,96,94,95,95,96,95,96,94,94,95,95,96,96,95,96,96,96,96,96,97,98,97,97,99,99,102,100,101,102,104,193,199,213,228,236,229,233,
    96,96,97,97,96,97,97,97,97,99,99,99,99,101,100,102,104,106,163,163,162,109,102,100,101,100,101,100,100,99,100,99,100,100,100,100,100,100,99,99,99,100,99,99,99,100,99,99,100,100,100,100,100,100,102,107,186,108,108,195,143,205,229,211,233,234,235,242,231,
    100,101,101,101,101,102,102,102,102,102,102,103,103,105,105,106,106,106,107,109,108,108,119,106,106,105,105,105,104,104,104,104,104,104,104,102,104,104,103,103,103,102,103,103,102,103,103,103,104,103,102,103,104,106,198,218,227,228,235,224,231,226,215,211,213,213,214,224,215,
    105,105,105,105,106,106,106,107,107,107,108,108,108,108,109,110,111,110,110,111,111,111,111,111,111,111,111,110,109,110,109,110,109,109,108,109,108,107,108,107,108,107,107,107,107,106,107,107,107,107,107,121,133,112,162,188,211,226,223,217,214,217,214,219,209,192,188,194,193,
    110,110,110,110,111,111,111,112,112,113,113,114,113,114,114,114,114,114,114,115,116,115,116,116,116,116,116,115,115,115,114,115,115,115,114,114,114,113,113,116,114,114,123,114,112,112,113,113,112,112,113,118,131,176,195,187,175,195,204,220,204,191,184,183,181,186,185,181,178,
    115,115,116,115,115,115,116,116,117,117,118,118,119,119,118,120,120,120,120,121,121,121,122,122,122,121,121,121,120,122,122,121,120,121,120,119,121,128,165,166,166,185,171,189,169,117,119,118,118,118,119,119,122,124,150,153,163,176,208,202,199,218,220,205,189,190,186,192,205,
    119,120,120,120,121,122,121,122,122,123,123,123,123,125,125,126,126,125,126,128,128,129,129,132,128,132,129,128,128,128,128,128,128,128,144,148,136,133,130,127,140,145,156,127,133,135,157,176,170,145,123,123,124,125,127,128,129,161,200,204,214,190,212,200,200,186,179,196,193,
    124,125,125,126,126,126,126,127,127,128,128,130,131,131,131,133,132,132,134,168,242,138,137,136,136,136,141,135,135,135,136,206,137,180,185,173,185,133,131,131,130,130,130,130,132,129,129,131,131,134,129,130,131,131,132,160,193,195,199,186,190,215,201,224,211,204,204,213,199,
    130,131,131,131,131,131,132,132,133,134,134,135,137,140,246,242,139,156,227,231,245,248,234,144,168,143,195,208,143,142,192,220,218,223,234,234,229,148,139,138,137,136,136,135,135,135,134,134,135,136,136,136,137,139,143,235,218,195,221,183,184,200,190,200,203,187,181,172,169,
    134,135,136,136,137,137,137,138,138,140,140,142,225,246,248,249,250,195,227,228,226,232,235,224,229,222,197,178,195,202,225,187,204,208,208,205,208,208,194,145,143,142,142,142,142,141,143,147,148,143,143,143,220,237,222,228,243,243,243,221,219,198,165,192,189,189,175,163,156,
    141,141,142,142,142,143,144,144,145,145,151,230,212,217,240,243,247,218,201,204,205,212,207,198,189,192,220,197,202,214,218,227,204,202,190,188,194,205,194,219,193,161,181,196,174,198,183,185,192,202,203,207,206,237,215,202,230,242,243,231,238,224,226,225,220,196,178,191,200,
    147,147,147,147,148,149,151,180,178,164,219,199,236,206,205,208,230,212,228,217,217,230,62,187,211,194,191,199,199,207,230,233,214,190,226,222,234,233,234,200,209,194,206,202,196,202,194,203,209,219,224,204,198,192,193,188,213,215,214,188,240,235,185,212,223,233,188,184,187,
    151,152,153,154,171,182,204,214,209,221,193,183,204,201,213,215,206,214,218,225,232,206,124,57,195,197,182,185,177,200,197,199,199,199,202,205,205,203,206,213,222,196,188,200,212,232,226,221,205,197,195,202,192,198,197,177,177,192,196,212,226,221,212,225,213,209,202,196,209,
    157,158,159,169,207,186,193,199,187,178,179,163,165,164,163,169,207,199,190,169,147,209,72,95,193,197,192,181,212,190,191,198,195,211,195,182,178,180,176,183,201,191,192,215,226,229,172,183,181,191,198,209,195,209,193,198,184,191,201,178,187,186,210,218,219,214,183,178,180,
    163,191,169,218,182,194,193,201,205,193,202,214,208,192,173,200,209,173,200,190,192,120,67,60,183,189,216,198,195,180,189,190,168,170,177,185,199,199,195,220,206,189,205,205,203,208,228,194,206,211,203,207,202,212,218,194,208,189,191,194,195,194,183,185,188,187,192,186,190,
    168,175,191,195,196,195,193,202,188,190,200,200,195,175,184,109,192,199,186,175,135,121,69,68,137,189,180,196,186,148,177,191,215,225,212,207,189,200,203,200,213,199,189,198,207,198,196,198,196,211,200,200,203,196,200,198,201,196,194,192,188,184,178,194,181,173,178,181,170,
    173,173,173,173,163,171,130,180,193,188,209,207,101,138,139,191,199,200,86,121,130,115,79,77,155,189,172,162,166,179,181,190,195,187,188,194,195,174,186,197,201,200,198,197,137,186,197,193,187,188,207,210,194,184,161,119,147,168,130,204,130,146,147,145,179,202,183,129,127,
    132,155,139,136,166,129,123,109,115,149,111,150,207,188,209,215,207,98,106,154,108,127,89,75,140,163,164,175,180,185,181,177,176,94,100,206,196,207,191,203,184,172,145,147,172,180,136,130,103,105,113,125,142,162,131,132,129,137,138,143,106,123,122,140,182,111,97,90,100,
    128,141,168,108,135,124,130,175,144,176,149,153,169,210,178,182,106,96,121,112,138,148,68,66,149,190,152,172,177,166,180,195,179,177,94,98,91,118,113,84,84,130,81,87,143,105,101,100,98,97,97,98,99,96,114,140,104,99,122,96,148,130,96,98,90,90,79,77,54,
    179,141,130,151,164,162,199,192,164,150,193,149,191,169,175,169,126,164,101,113,169,132,149,73,178,132,101,188,199,189,182,208,175,138,81,81,79,83,84,84,83,80,91,95,103,80,77,134,154,135,98,120,101,111,90,124,86,96,88,72,68,87,103,55,78,59,97,60,54,
    152,167,143,161,122,172,164,148,183,156,155,169,168,197,182,164,200,152,122,134,150,169,152,118,138,80,135,210,216,180,115,214,201,207,81,81,86,82,74,73,74,77,83,84,76,74,93,77,88,102,86,103,81,102,77,95,163,152,97,83,86,86,109,120,93,65,145,150,70,
    105,131,147,147,158,187,190,195,152,207,192,191,180,186,91,78,57,105,114,130,158,75,190,126,84,106,92,68,97,102,142,145,200,176,75,129,123,73,79,76,72,76,79,70,73,76,73,76,88,77,76,74,84,125,103,96,112,82,86,88,162,170,150,154,161,126,126,139,120,
    137,161,143,149,167,170,196,182,209,206,194,169,155,66,101,71,59,70,72,154,151,95,169,129,67,62,78,67,73,68,128,121,123,181,197,79,71,82,80,83,86,83,85,61,71,71,81,76,77,89,101,78,140,134,149,76,137,163,99,173,176,169,175,168,61,147,152,123,173,
    113,129,155,158,167,97,100,195,165,208,147,142,107,115,59,61,49,150,147,184,126,66,121,158,143,76,68,85,80,88,151,152,108,124,125,102,79,77,85,79,72,67,81,73,74,72,98,86,83,130,115,125,122,99,133,166,127,131,149,180,152,85,140,116,152,44,38,44,33,
    79,96,169,201,195,85,145,207,114,136,88,82,140,88,105,72,94,92,74,110,83,61,109,162,104,86,53,89,106,89,124,161,165,129,85,93,88,71,71,107,74,87,73,76,67,74,79,96,93,65,94,128,158,151,195,134,141,128,71,73,83,74,147,44,40,42,79,36,46,
    115,107,98,148,135,92,99,138,138,111,116,72,86,59,91,100,100,95,142,80,121,119,109,98,89,73,71,109,91,151,153,128,132,72,151,168,176,142,72,80,73,95,78,84,84,76,71,69,71,76,123,82,76,131,114,85,126,132,173,158,112,120,39,37,41,34,44,36,58,
    159,131,116,90,99,84,90,170,106,98,125,72,121,157,172,152,104,69,56,116,141,126,153,88,135,137,129,111,115,141,80,116,79,76,70,122,89,121,79,144,105,81,74,98,78,75,65,75,74,98,103,112,116,112,120,140,97,60,72,70,59,41,48,60,48,44,52,60,74,
    145,171,96,121,115,135,125,143,137,113,132,124,144,128,97,66,63,69,80,97,111,81,124,79,57,67,142,129,119,72,89,150,101,105,127,92,137,115,118,129,120,145,94,70,73,70,73,72,70,76,87,73,92,91,106,96,92,111,79,75,82,45,57,49,57,59,56,73,103,
    132,164,131,88,76,82,169,124,102,113,112,125,144,152,165,65,66,68,99,106,100,122,80,77,61,71,139,142,63,67,84,128,97,112,130,59,108,117,89,90,82,166,137,146,108,108,86,70,72,95,75,99,86,72,71,92,84,93,94,102,126,52,48,75,74,59,41,83,129,
    155,177,77,75,73,154,163,117,147,124,114,130,147,136,140,85,159,102,124,138,65,60,63,65,83,62,123,163,84,62,104,137,63,113,118,100,105,95,70,90,70,128,66,141,117,175,162,77,145,74,102,91,87,92,75,108,89,111,119,128,117,67,87,105,95,57,85,187,139,
    79,70,72,71,71,141,93,157,174,148,154,161,89,63,141,167,101,108,162,57,69,76,55,72,69,69,65,129,126,120,88,120,122,172,105,80,92,62,66,64,111,48,55,75,55,132,122,136,66,96,83,102,85,70,92,99,108,103,128,138,213,131,115,140,127,80,140,183,171,
    71,71,74,71,108,174,138,150,190,116,81,93,95,94,101,191,105,164,79,59,76,61,70,64,73,90,116,60,70,61,84,153,178,150,129,60,63,74,67,67,62,67,81,74,93,129,92,77,63,67,82,118,90,124,71,69,115,142,95,131,159,133,161,120,135,90,141,139,141,
    70,77,68,135,172,147,126,137,172,111,90,76,129,70,136,117,93,91,123,71,116,80,65,73,54,78,128,74,98,156,162,161,158,107,73,59,62,51,66,54,53,85,89,111,85,121,77,74,53,59,60,86,110,86,84,80,134,118,148,125,111,129,83,143,139,90,68,175,161,
    65,70,75,74,170,129,165,111,146,95,121,128,106,129,123,159,102,147,164,123,143,62,79,141,68,124,145,149,144,135,145,158,159,109,94,60,55,86,61,62,76,59,70,62,120,71,89,52,100,72,63,74,50,88,119,112,75,126,160,145,153,177,125,126,82,132,134,161,140,
    108,68,82,147,153,84,123,143,169,80,93,95,71,140,129,155,133,92,130,133,138,104,102,116,127,118,153,120,136,109,163,157,205,62,88,81,51,62,54,119,66,52,75,67,84,61,88,53,46,74,113,66,153,60,45,71,120,124,140,200,165,171,72,82,97,92,144,153,58,
    66,69,70,94,97,63,106,110,122,91,112,187,121,110,144,158,78,144,116,102,113,109,149,141,102,104,96,133,114,90,155,156,121,71,51,51,43,48,61,61,72,60,66,56,97,104,77,65,53,46,65,73,90,79,56,70,60,116,72,158,62,206,65,100,67,62,65,107,78,
    69,74,131,165,105,104,102,136,88,68,145,137,118,149,91,119,116,137,105,126,100,112,106,71,95,104,102,161,128,125,144,184,118,57,132,162,76,76,96,145,107,90,63,64,66,66,64,66,107,85,69,120,97,121,66,76,81,92,73,94,65,94,169,65,113,61,56,71,41,
    70,65,77,85,77,69,131,121,61,105,146,134,106,123,78,163,109,112,110,166,105,69,97,109,138,142,143,142,145,167,137,115,136,119,168,124,77,116,93,114,64,108,107,68,83,51,73,105,117,126,111,54,86,91,101,60,99,59,60,83,61,160,145,130,60,57,69,86,62,
    89,70,130,74,102,67,61,86,74,137,107,132,111,93,150,62,142,114,145,106,101,92,131,98,88,110,105,146,143,151,173,117,153,111,131,124,96,115,125,104,81,120,134,86,111,86,81,64,101,112,93,93,88,117,93,57,58,41,73,55,66,60,66,52,52,69,75,14,32,
    98,152,102,119,68,134,73,83,112,146,139,80,110,112,140,108,91,102,108,72,114,100,119,108,72,85,161,129,161,174,122,120,155,81,110,91,144,153,97,131,89,113,125,127,109,71,69,103,90,139,113,68,89,126,90,109,43,48,53,49,58,65,59,67,133,127,113,81,81,
    124,132,136,59,119,75,108,170,103,89,116,82,92,147,152,114,118,125,98,115,127,108,130,124,94,105,178,129,120,140,112,110,63,104,120,95,126,135,116,82,98,97,152,89,109,99,52,90,83,123,151,90,110,85,86,141,132,66,67,58,67,89,71,103,86,106,110,61,40,
    127,119,71,171,97,140,100,73,72,67,88,86,94,104,115,80,84,142,87,120,122,125,106,122,101,138,111,116,179,126,63,78,96,69,154,114,118,66,115,62,70,164,117,64,140,65,96,90,96,92,129,81,116,144,117,113,74,66,120,58,78,84,81,85,67,129,117,41,113,
    144,92,126,117,148,152,96,82,85,68,69,72,123,119,56,74,156,118,119,160,115,113,141,123,122,58,84,150,87,143,76,132,58,103,99,81,57,64,94,57,118,105,96,100,59,67,74,107,68,105,134,140,91,137,153,123,74,37,65,82,66,80,101,68,54,63,50,119,79,
    61,65,107,166,132,96,154,93,81,140,99,70,107,127,87,100,67,71,149,104,75,120,128,121,139,69,94,113,123,136,146,115,83,125,134,101,67,54,70,95,79,144,81,58,59,65,70,114,78,98,130,153,83,99,136,56,116,109,95,95,62,68,59,76,49,58,14,83,72,
    64,66,82,69,93,109,91,73,169,69,101,125,69,80,117,41,60,113,119,93,99,98,118,108,127,95,124,163,124,134,148,80,142,127,107,67,95,67,84,101,121,137,122,101,49,57,63,88,81,88,100,109,147,146,49,69,46,66,67,46,97,79,66,110,60,66,17,36,74,
    72,62,59,59,78,204,94,110,100,109,100,137,82,121,131,117,113,146,84,88,98,106,120,149,126,116,150,121,141,140,112,88,108,68,121,109,127,73,70,121,134,150,71,65,88,87,70,60,102,108,96,154,120,152,68,68,58,88,36,87,61,103,96,123,79,57,65,40,51,
},
{
    144,146,144,145,144,144,144,146,145,144,144,145,145,148,160,176,176,160,188,190,166,170,147,147,147,146,145,144,146,145,144,145,145,144,144,145,145,143,143,144,145,143,144,143,143,145,144,144,145,144,144,146,145,146,148,148,150,149,152,151,152,154,206,207,222,236,242,236,238,
    148,147,147,147,148,147,148,148,148,148,149,149,149,149,152,152,152,154,177,179,178,153,150,149,149,150,150,149,149,148,149,149,149,148,148,148,148,147,149,146,147,147,148,147,148,147,148,148,148,149,149,149,149,150,150,156,201,156,156,209,174,213,236,216,236,237,239,244,235,
    153,152,154,152,153,151,151,152,152,152,152,153,153,155,154,154,154,154,156,155,156,155,159,155,155,154,154,153,154,154,154,153,152,152,152,153,152,152,152,151,151,152,150,150,151,152,151,151,151,150,153,153,153,154,206,222,231,232,238,230,235,229,221,217,219,220,220,227,221,
    157,155,155,157,156,156,157,156,156,157,157,157,158,158,158,157,158,158,159,159,158,158,159,158,159,158,158,158,158,156,157,156,156,157,157,156,156,155,155,154,155,154,154,155,155,155,154,154,155,155,156,161,165,157,176,196,215,229,226,219,216,220,219,223,214,201,197,200,202,
    161,160,160,161,160,159,160,160,160,161,161,162,163,162,162,162,162,161,163,162,163,163,162,162,162,162,162,163,163,160,161,162,161,161,161,160,160,160,159,161,158,160,163,159,159,158,159,158,158,159,159,162,167,184,198,194,187,201,208,221,207,201,191,190,188,192,192,190,190,
    165,165,164,164,165,165,164,165,166,165,166,165,165,166,166,164,166,166,167,167,166,167,167,167,166,167,167,167,167,166,167,167,166,166,166,166,164,166,176,177,177,192,183,195,180,163,162,162,162,163,163,163,164,166,175,175,179,187,211,207,203,219,221,209,197,197,194,198,208,
    169,169,168,168,167,167,169,169,168,168,167,169,170,171,170,170,170,171,170,169,171,172,171,171,170,173,171,171,171,171,170,171,170,169,175,169,170,171,170,168,172,170,174,168,169,167,177,184,180,171,166,166,167,168,169,170,171,182,205,210,217,197,215,203,204,194,187,201,200,
    172,173,172,173,172,173,172,172,172,173,173,172,173,174,174,174,174,174,176,192,242,178,177,176,176,176,176,176,176,175,176,212,175,190,193,188,193,174,172,172,171,171,171,171,171,171,170,171,172,172,171,171,171,172,173,182,200,202,204,193,196,215,205,224,214,207,207,215,205,
    177,176,175,176,176,176,175,175,177,176,177,177,178,180,245,241,180,184,227,232,243,246,235,183,190,181,202,213,181,181,200,219,217,223,233,233,228,180,178,176,176,176,176,176,175,174,175,175,176,175,175,176,177,179,178,234,222,202,223,197,196,203,198,204,206,193,189,181,180,
    179,180,178,180,179,178,179,179,179,180,180,183,228,245,247,248,247,201,227,227,225,231,234,223,228,221,201,186,199,208,224,194,204,208,208,207,209,209,200,181,181,180,180,180,178,180,177,179,180,179,179,179,220,233,221,228,238,238,238,222,220,205,190,197,195,194,182,173,167,
    182,183,182,182,183,184,184,184,185,185,186,231,215,218,240,242,245,219,204,205,206,211,206,201,193,195,220,200,203,213,217,224,205,204,193,191,195,205,197,218,197,184,190,200,191,202,191,193,199,206,207,208,208,233,216,206,228,237,238,229,233,223,224,223,220,199,185,195,204,
    187,187,187,187,188,189,189,198,196,188,220,204,234,208,207,210,229,213,227,216,216,225,76,179,203,188,186,189,190,207,225,227,213,193,223,219,229,228,230,201,208,195,206,201,196,203,198,203,209,218,220,205,200,195,197,191,213,214,215,194,234,230,189,211,221,228,194,190,191,
    190,191,189,189,188,195,207,213,210,220,199,191,205,204,213,213,208,212,216,221,226,207,127,71,190,192,177,176,169,189,198,201,200,200,202,206,205,203,206,212,219,198,197,200,209,224,221,216,204,199,196,202,194,199,199,183,184,195,196,211,221,218,211,221,212,208,203,198,210,
    194,193,192,192,211,194,198,203,194,191,191,194,190,190,193,183,208,201,194,173,146,207,79,100,187,189,182,173,200,185,194,199,197,210,196,186,182,184,180,185,200,194,194,212,221,223,195,195,195,196,199,207,197,208,197,199,188,192,201,184,189,189,208,214,214,212,186,185,187,
    195,203,195,217,193,199,199,204,207,199,204,213,208,200,187,203,209,180,195,184,188,121,77,73,179,179,202,189,186,175,175,193,176,178,181,187,199,199,196,215,205,197,205,204,202,207,221,203,207,210,204,205,202,209,214,195,205,193,195,196,196,194,188,189,192,189,194,189,193,
    199,193,198,200,201,199,198,203,194,199,202,202,199,195,198,117,187,194,184,169,132,121,79,79,136,184,172,189,177,144,169,178,210,216,208,205,193,200,202,200,208,199,192,199,204,199,197,199,198,208,200,200,203,198,201,198,200,198,195,193,191,192,186,196,187,183,184,186,179,
    200,198,198,198,165,190,137,190,198,191,207,206,105,143,133,180,184,195,104,118,129,114,85,87,154,185,164,158,161,172,171,177,195,192,191,194,195,183,190,199,200,201,199,198,154,192,198,196,192,192,203,205,197,191,174,139,154,174,150,202,149,155,157,153,174,197,186,149,148,
    140,157,143,139,163,134,132,117,123,150,112,151,196,181,204,207,202,112,106,149,111,128,94,88,138,161,161,171,174,180,171,166,155,100,101,201,195,204,184,192,179,171,147,148,170,175,140,133,111,114,120,134,153,161,139,148,146,148,147,152,123,131,131,147,173,122,115,111,121,
    140,153,170,120,136,128,130,168,146,170,148,155,171,209,178,182,120,110,117,111,136,148,75,75,145,182,144,162,169,155,167,182,168,172,97,101,95,115,113,92,90,128,91,95,141,114,108,107,108,107,105,107,108,107,123,143,128,123,139,119,148,134,107,108,104,106,103,101,71,
    174,145,131,150,166,160,193,185,160,145,190,146,188,169,175,170,134,158,100,114,168,133,142,80,170,122,101,177,190,173,172,196,161,129,82,81,79,80,82,84,88,85,92,93,99,77,77,128,150,129,100,120,106,113,101,128,104,109,102,86,84,101,114,73,91,75,109,74,68,
    154,164,144,156,125,166,159,149,179,157,150,166,169,191,182,165,190,145,118,132,149,162,143,103,125,67,130,195,203,167,104,203,190,196,74,75,75,76,73,72,74,75,79,80,75,76,91,72,84,98,82,96,76,98,98,112,161,151,115,102,103,103,121,124,91,73,134,144,72,
    112,140,152,153,159,181,183,188,154,202,185,188,179,182,87,74,55,103,111,130,157,78,178,116,80,98,82,55,85,93,131,138,189,162,69,119,111,69,70,67,69,70,73,69,70,74,71,72,83,70,72,70,76,114,92,90,104,96,103,106,162,167,150,154,160,127,120,134,119,
    140,161,148,152,167,164,190,177,203,201,191,167,156,62,95,65,53,57,63,148,151,96,163,116,53,55,72,56,60,51,120,115,116,171,180,66,65,74,70,73,81,77,79,61,64,67,78,73,73,82,101,70,132,125,140,73,132,154,115,168,173,166,173,166,66,143,152,125,169,
    115,127,155,158,167,95,96,188,164,204,150,137,112,114,54,56,47,141,136,179,130,77,118,151,137,61,64,72,63,75,136,140,99,118,109,88,64,72,75,65,65,62,73,64,68,69,94,75,76,126,112,122,121,103,129,154,119,125,149,176,150,83,136,113,151,56,46,56,40,
    82,96,169,195,188,85,139,201,113,129,92,77,138,87,101,69,85,89,61,92,75,72,101,156,89,64,50,75,91,76,112,151,147,115,68,73,72,61,63,102,63,76,68,63,61,66,70,84,83,65,91,127,153,145,181,123,133,121,63,70,84,76,145,57,54,55,83,47,54,
    111,114,103,149,135,84,92,136,136,107,110,68,79,69,93,101,101,91,134,69,119,115,100,91,77,56,54,101,81,147,142,116,119,61,136,154,159,130,55,67,63,84,70,68,74,67,63,60,62,63,117,79,69,127,114,82,120,127,168,153,111,114,54,50,55,45,61,47,67,
    158,133,115,90,103,88,91,163,106,98,125,64,120,151,167,150,103,62,53,108,135,125,149,74,125,124,119,99,111,132,67,112,67,63,60,110,79,117,68,132,88,62,56,86,72,65,56,62,61,99,102,109,111,105,114,131,87,57,69,67,57,54,60,73,63,56,61,67,78,
    144,169,98,125,113,141,124,142,135,114,131,126,143,126,96,61,56,60,74,82,109,79,113,66,49,53,129,125,112,54,81,142,90,91,121,84,124,110,107,113,113,135,70,52,58,58,59,60,59,61,72,67,88,88,95,90,78,103,75,71,88,57,68,62,69,69,69,79,102,
    136,159,131,99,77,82,167,121,94,114,114,124,142,150,159,61,59,59,94,102,93,121,60,52,46,46,131,138,53,52,62,124,97,105,126,54,102,105,79,78,73,154,124,134,95,91,65,54,56,85,64,96,74,67,49,80,85,91,89,103,124,65,62,85,84,72,52,81,127,
    153,173,75,73,72,154,164,120,146,121,113,128,144,133,128,77,152,91,122,135,52,44,43,45,64,51,114,158,73,48,96,130,58,106,117,92,103,84,53,78,53,112,52,132,103,161,152,58,130,67,94,91,82,83,72,98,78,107,115,129,115,79,93,109,98,67,88,178,133,
    80,70,71,74,71,140,96,152,170,145,153,158,80,55,130,160,97,97,158,46,51,59,44,48,48,49,53,122,120,107,72,108,118,163,105,74,89,46,41,45,101,40,38,48,47,125,109,127,47,81,74,100,84,62,94,95,100,94,123,137,202,132,118,139,128,76,138,177,165,
    71,70,74,75,111,173,130,147,184,108,77,91,91,85,100,185,102,151,62,47,58,42,52,46,53,68,109,50,52,47,71,140,174,144,125,46,51,58,43,44,46,52,60,53,89,122,78,54,43,46,65,104,74,116,57,55,110,140,97,129,154,132,158,121,135,95,139,138,132,
    71,79,70,133,168,145,124,137,165,110,87,70,128,64,128,106,85,83,110,61,104,66,45,53,45,65,122,62,93,152,155,153,152,105,62,42,49,39,50,38,46,82,86,106,74,115,62,59,38,40,41,61,101,76,63,68,129,104,144,120,118,124,77,141,139,91,67,172,156,
    67,68,72,73,170,129,163,114,143,93,124,125,105,128,123,149,103,137,152,115,139,51,70,136,56,113,138,144,138,130,139,152,151,99,84,54,46,75,43,49,57,39,52,52,112,55,73,40,83,51,52,60,37,77,105,97,56,120,155,141,145,172,126,124,83,131,133,159,133,
    109,70,82,147,155,80,123,145,168,76,96,99,66,140,129,152,132,85,126,130,136,100,90,111,121,114,148,113,127,106,160,152,198,53,79,67,35,43,40,109,51,36,59,48,84,55,85,38,36,59,104,44,139,48,38,54,114,116,138,194,160,166,57,66,98,88,140,149,47,
    66,65,72,93,94,61,106,114,123,90,113,182,119,111,141,154,75,140,113,101,109,104,143,139,101,102,88,129,105,83,152,150,113,60,40,40,37,35,45,40,71,44,47,47,96,103,52,42,45,38,53,61,81,58,42,47,45,111,50,153,50,201,52,88,50,64,52,94,39,
    65,70,128,162,101,103,108,135,93,60,138,137,117,145,92,116,115,134,102,123,95,97,92,61,85,99,95,158,121,114,139,178,106,46,118,150,63,66,84,139,96,84,49,43,48,49,41,44,87,72,51,106,93,111,54,65,68,74,62,80,46,94,157,56,110,50,43,40,18,
    68,64,75,81,74,60,133,120,56,106,147,131,108,123,70,163,101,108,107,160,94,56,87,101,133,136,139,137,141,165,136,110,132,112,159,120,60,102,90,109,55,103,101,61,84,43,63,100,107,122,103,57,82,87,94,47,87,49,53,76,60,151,142,127,47,43,62,46,35,
    87,62,127,69,101,60,58,87,67,140,108,131,112,90,150,56,140,110,138,95,98,84,121,92,88,105,95,140,136,148,168,114,149,107,125,121,90,110,122,103,76,109,123,67,100,75,65,46,100,106,89,91,88,113,92,49,46,49,66,44,50,46,47,39,42,48,31,6,14,
    101,153,109,119,59,130,65,76,112,146,136,77,102,113,143,107,93,100,105,58,112,91,108,96,65,83,155,120,155,168,120,117,147,72,105,90,139,149,93,123,84,109,108,123,106,54,50,96,80,133,106,68,83,123,78,97,41,44,49,43,50,50,43,47,121,124,99,56,39,
    123,133,137,56,119,72,105,163,107,86,109,74,91,147,153,114,118,121,98,112,126,99,125,118,94,97,167,115,118,135,110,106,52,102,115,92,122,134,110,82,87,81,148,78,108,96,40,78,75,106,143,80,107,86,83,131,125,71,65,48,59,77,67,92,76,99,107,27,26,
    126,123,66,172,98,141,98,72,60,61,78,82,94,107,117,71,88,142,75,117,120,124,102,120,103,136,102,110,176,120,50,74,90,57,149,107,114,56,111,43,64,158,111,56,132,61,90,82,90,89,122,71,110,137,112,99,69,69,115,45,71,79,80,73,48,123,115,24,83,
    138,98,128,121,148,153,102,81,77,62,61,65,121,121,51,64,146,116,120,156,114,110,137,117,119,51,66,146,79,137,66,118,48,97,94,66,44,48,88,44,106,103,91,96,45,54,56,98,50,105,128,138,82,131,150,117,73,43,70,80,66,67,100,47,46,48,23,111,45,
    59,60,102,164,133,95,150,100,85,140,99,62,108,125,88,103,63,58,148,102,67,118,124,119,137,60,83,110,121,127,137,107,82,123,124,95,55,45,54,90,65,134,66,42,46,51,58,101,64,94,129,145,77,94,129,52,104,109,93,89,51,50,49,63,42,42,7,37,53,
    59,59,76,71,96,113,89,71,170,66,103,123,71,86,117,49,50,108,121,93,100,97,117,106,126,97,121,158,122,132,143,72,132,117,99,57,88,58,75,98,114,134,116,94,38,42,42,64,71,77,95,109,141,132,40,72,52,71,63,49,93,79,53,100,42,61,7,16,32,
    60,56,58,54,70,201,97,116,107,114,103,139,80,123,133,118,110,142,70,87,97,103,118,146,121,108,143,117,136,135,110,86,110,64,108,96,121,66,57,116,123,148,58,53,76,73,57,46,101,103,95,151,114,143,59,74,60,89,38,88,66,99,96,121,65,44,52,20,28,
},
};

using namespace boost::gil;
extern rgb8c_planar_view_t sample_view;
rgb8c_planar_view_t sample_view = planar_rgb_view(69,46,halfdome[0],halfdome[1],halfdome[2],69);
