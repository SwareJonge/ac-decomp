#include "jaudio_NES/game64.h"

#include "m_name_table.h"

// TODO: finish

#pragma force_active on

// clang-format off
static const u8 SEQ_TABLE[256] = {
    247,  81,  82,  83,
    84,  85,  86,  87,
    88,  89,  90,  91,
    92,  93,  94,  95,
    96,  97,  98,  99,
    100, 101, 102, 103,
    104, 176, 178, 218,
    219, 220, 222, 223,
    224, 225, 226, 227,
    229, 169, 170, 171,
    68, 166,  60,  59,
    168, 177,  74,  62,
    63,  64,  65,  66,
    67, 214, 215, 216,
    217, 228,  57, 231,
    221, 230, 167,  70,
    71,  73,  75,  78,
    79, 105,  58,  69,
    72, 232, 233, 234,
    235, 179,  76, 172,
    173, 174, 175, 247,
    247, 247, 247, 247,
    180, 181, 182, 183,
    184, 185, 186, 187,
    188, 189, 190, 191,
    192, 193, 194, 195,
    196, 197, 198, 199,
    200, 201, 202, 203,
    204, 205, 206, 207,
    208, 209, 210, 211,
    212, 213,  77,  61,
    77,  80, 247, 247,
    111, 112, 113, 114,
    115, 116, 117, 118,
    119, 120, 121, 122,
    123, 124, 125, 126,
    127, 128, 129, 130,
    131, 132, 133, 134,
    135, 136, 137, 138,
    139, 140, 141, 142,
    143, 144, 145, 146,
    147, 148, 149, 150,
    151, 152, 153, 154,
    155, 156, 157, 158,
    159, 160, 161, 162,
    163, 164, 165, 247,
    247, 247, 247, 247,
    247, 247, 247, 247,
    0,   1,   2,   3,
    4,   5,   6,   7,
    8,   9,  10,  11,
    12,  13,  14,  15,
    16,  17,  18,  19,
    20,  21,  22,  23,
    24,  25,  26,  27,
    28,  29,  30,  31,
    32,  33,  34,  35,
    36,  37,  38,  39,
    40,  41,  42,  43,
    44,  45,  46,  47,
    48,  49,  50,  51,
    52,  53,  54,  55,
    56,  57, 236, 237,
    241, 238, 240, 239
};

static const u16 SE_FLOOR_DATA[FLOOR_ALL_NUM] ATTRIBUTE_ALIGN(2) = {
    27, 27, 32, 31,
    28, 32, 31, 27,
    27, 28, 29, 29,
    27, 31, 28, 30,
    33, 27, 30, 27,
    32, 32, 31, 28,
    32, 27, 35, 32,
    32, 32, 27, 29,
    31, 32, 28, 28,
    28, 27, 28, 28,
    27, 31, 36, 32,
    28, 27, 33, 27,
    35, 28, 32, 32,
    28, 28, 32, 29,
    28, 33, 27, 32,
    33, 27, 32, 32,
    28, 32, 32, 34,
    32, 32, 27, 32,
    28, 27, 29, 27,
    28, 28, 27, 31,
    28, 31, 28, 32,
    28, 32, 32, 32,
    32, 32, 32, 32,
    32, 32, 32
};

// ATTRIBUTE_ALIGN(4)
static const u16 SE_ROOM_INS_DATA[] ATTRIBUTE_ALIGN(2) = {
    0x505, 0x509, 0x50D, 0x511,
    0x515, 0x519, 0x51D, 0x521,
    0x525, 0x529, 0x501, 0x52D,
    0x531, 0x535, 0x539, 0x53D,
    0
};

static const u16 SE_ROOM_INS_RANDOM_OFFSET[] = {
    11, 11, 11, 10,
    10, 10, 12, 100,
    20, 100, 45, 10,
    4, 9, 2, 1,
    0
};

static const u8 SHIIN2BOIN[] = {
    0,   1,   2,   3,
    4,   5,   1,   2,
    3,   4,   5,   1,
    2,   3,   4,   5,
    1,   2,   3,   4,
    5,   1,   2,   3,
    4,   5,   1,   2,
    3,   4,   5,   1,
    2,   3,   4,   5,
    1,   3,   5,   1,
    2,   3,   4,   5,
    1,  45,   1,   2,
    3,   4,   5,   1,
    2,   3,   4,   5,
    1,   4,   5,   1,
    2,   3,   4,   5,
    1,   2,   3,   4,
    5,   1,   2,   3,
    4,   5,   3,   1,
    3,   5,   0,   0,
    0,   0,   0,   0,
    0,   0
};

static const u8 TRGPRIO[] = {
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  60,  60,  60,
    60,  60,  60,  60,
    60,  70,  70,  70,
    70,  70,  70,  70,
    70,  70,  70,  70,
    70,  70,  70,  70,
    70,  70,  70,  70,
    70,  70,  70,  70
};

static const u8 sou_trg_se_init[] ATTRIBUTE_ALIGN(4) = {
    0,   0,   0,   0,
    0,   0,   0,   0,
    63, 128,   0,   0,
    63, 128,   0,   0,
    63, 128,   0,   0,
    63, 128,   0,   0,
    63,   0,   0,   0,
    0,   0,   0,   0
};

static const u8 sou_voice_se_init[] ATTRIBUTE_ALIGN(4) = {
    0,   0,   0,   0,
    0,   0,   0,   0,
    63, 128,   0,   0,
    63, 128,   0,   0,
    63, 128,   0,   0,
    63, 128,   0,   0,
    63, 128,   0,   0,
    63, 128,   0,   0,
    63,   0,   0,   0
};

static const u8 sou_lev_se_init[] ATTRIBUTE_ALIGN(4) = {
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    63, 128,   0,   0,
    63,   0,   0,   0
};

static const u8 sou_lev_ongen_data_init[] ATTRIBUTE_ALIGN(4) = {
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    70,  28,  60,   0,
    70,  28,  60,   0
};

static const u8 sou_ongen_entry_init[] ATTRIBUTE_ALIGN(4) = {
    0,   0,   0,   0,
    0,   0,   0,   0,
    63,   0,   0,   0,
    70,  28,  60,   0
};

static const u8 sou_se_fade_init[] ATTRIBUTE_ALIGN(4) = {
    0,   0,   0,   0,
    0,   0,   0,   0,
    63, 128,   0,   0
};

// force data pooling
FORCESTRIP static int __REMOVE_TEMP() {
    int a = SEQ_TABLE[55];
    int b = SE_FLOOR_DATA[3];
    int c = SE_ROOM_INS_DATA[6];

    return a * b * c;
}

// clang-format on

#pragma force_active reset
