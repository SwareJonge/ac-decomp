#ifndef ROOM_TYPE_H
#define ROOM_TYPE_H

#include "types.h"
#include "libu64/gfxprint.h"
#include "m_actor_type.h"

#define mRmTp_FTR_UNIT_MAX 4

enum {
  mRmTp_FTRSIZE_1x1, /* x */
  mRmTp_FTRSIZE_1x2, /* yy OR y */
                     /*       y */
  mRmTp_FTRSIZE_2x2, /* zz */
                     /* zz */
  mRmTp_FTRSIZE_NUM
};

enum birth_type {
  mRmTp_BIRTH_TYPE_GRP_A = 0,
  mRmTp_BIRTH_TYPE_GRP_B = 1,
  mRmTp_BIRTH_TYPE_GRP_C = 2,
  mRmTp_BIRTH_TYPE_EVENT = 3,
  mRmTp_BIRTH_TYPE_BIRTHDAY = 4,
  mRmTp_BIRTH_TYPE_HALLOWEEN = 5,
  mRmTp_BIRTH_TYPE_HANIWA = 6,
  mRmTp_BIRTH_TYPE_LOTTERY = 7,
  mRmTp_BIRTH_TYPE_FTR_CLOTH = 8,
  mRmTp_BIRTH_TYPE_FTR_UMBRELLA = 9,
  mRmTp_BIRTH_TYPE_FTR_INSECT = 10,
  mRmTp_BIRTH_TYPE_FTR_FISH = 11,
  mRmTp_BIRTH_TYPE_SINGLE_FOSSIL = 12,
  mRmTp_BIRTH_TYPE_MULTI_FOSSIL = 13,
  mRmTp_BIRTH_TYPE_XMAS = 14,
  mRmTp_BIRTH_TYPE_SANTA = 15,
  mRmTp_BIRTH_TYPE_UNOBTAINABLE = 16,
  mRmTp_BIRTH_TYPE_SNOWMAN = 17,
  mRmTp_BIRTH_TYPE_HALLOWEEN_TRICK = 18,
  mRmTp_BIRTH_TYPE_POST_OFFICE = 19,
  mRmTp_BIRTH_TYPE_MARK_ROOM = 20,
  mRmTp_BIRTH_TYPE_SONCHO = 21,
  mRmTp_BIRTH_TYPE_JONASON = 22,
  mRmTp_BIRTH_TYPE_UNUSED_23 = 23,
  mRmTp_BIRTH_TYPE_FAMICOM_EREADER = 24,
  mRmTp_BIRTH_TYPE_ISLAND = 25,
  mRmTp_BIRTH_TYPE_FAMICOM_ISLAND = 26,
  mRmTp_BIRTH_TYPE_MY_ORIGINAL = 27,
  mRmTp_BIRTH_TYPE_FAMICOM_CODE = 28,
  mRmTp_BIRTH_TYPE_MUSEUM = 29,
  mRmTp_BIRTH_TYPE_SONCHO_LIGHTHOUSE_QUEST = 30,
  mRmTp_BIRTH_TYPE_FTR_DIARY = 31,
  mRmTp_BIRTH_TYPE_GROUNDHOG = 32,
  mRmTp_BIRTH_TYPE_KAMAKURA = 33,
  mRmTp_BIRTH_TYPE_NINTENDO_CODE = 34,
  mRmTp_BIRTH_TYPE_HARVEST_FESTIVAL = 35,
  mRmTp_BIRTH_TYPE_UNUSED_36 = 36,
  mRmTp_BIRTH_TYPE_SUMMER_CAMPER = 37,

  mRmTp_BIRTH_TYPE_NUM
};

typedef struct room_type_place_info_one_s {
  int exists;
  int ut_x;
  int ut_z;
} mRmTp_FtrPlaceInfoOne_t;

typedef struct room_type_place_info_s {
  mRmTp_FtrPlaceInfoOne_t units[mRmTp_FTR_UNIT_MAX];
} mRmTp_FtrPlaceInfo_t;

#define FTR_NUM 1266

#define FTR_GET_ROTATION(f) ((f) & 3)

// TEMPORARY. Should be generated with .decl files
#define ITEM0_NO_START 0x0000
#define ITEM0_1_NO_START ITEM0_NO_START + 0x800

#define FTR0_NO_START 0x1000

#define ITEM1_NO_START 0x2000
#define ITEM1_0_NO_START ITEM0_1_NO_START        // paper
#define ITEM1_1_NO_START ITEM1_NO_START + 0x100  // money
#define ITEM1_2_NO_START ITEM1_NO_START + 0x200  // tools
#define ITEM1_3_NO_START ITEM1_NO_START + 0x300  // fish
#define ITEM1_4_NO_START ITEM1_NO_START + 0x400  // clothing
#define ITEM1_5_NO_START ITEM1_NO_START + 0x500  // etc
#define ITEM1_6_NO_START ITEM1_NO_START + 0x600  // carpets
#define ITEM1_7_NO_START ITEM1_NO_START + 0x700  // wallpaper
#define ITEM1_8_NO_START ITEM1_NO_START + 0x800  // food
#define ITEM1_9_NO_START ITEM1_NO_START + 0x900  // seeds
#define ITEM1_A_NO_START ITEM1_NO_START + 0xA00  // mini disks
#define ITEM1_B_NO_START ITEM1_NO_START + 0xB00  // diaries
#define ITEM1_C_NO_START ITEM1_NO_START + 0xC00  // tickets
#define ITEM1_D_NO_START ITEM1_NO_START + 0xD00  // insects
#define ITEM1_E_NO_START ITEM1_NO_START + 0xE00  // hukubukuro
#define ITEM1_F_NO_START ITEM1_NO_START + 0xF00  // kabu

#define FTR1_NO_START 0x3000

extern void mRmTp_DrawFamicomInfo(gfxprint_t* gfxprint);
extern void mRmTp_MakeFamicom_Fdebug();

extern mActor_name_t mRmTp_FtrItemNo2Item1ItemNo(mActor_name_t ftr_item_no, void* unused); /* second paramter is probably GAME*? */
extern int mRmTp_FtrItemNo2FtrIdx(mActor_name_t ftr_item_no);
extern mActor_name_t mRmTp_FtrIdx2FtrItemNo(int ftr_idx, int rotation);
extern int mRmTp_GetFurnitureData(mActor_name_t ftr, int ut_x, int ut_z, mRmTp_FtrPlaceInfo_t* place_info);
extern int mRmTp_FurnitureIdx2FurnitureKind(int ftr_idx);
extern int mRmTp_PleaseDrawLightSwitch();

#endif