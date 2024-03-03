static void aSumLiccaLowChest_ct(FTR_ACTOR* ftr_actor, u8* data);
static void aSumLiccaLowChest_mv(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data);
static void aSumLiccaLowChest_dw(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data);
static void aSumLiccaLowChest_dt(FTR_ACTOR* ftr_actor, u8* data);

static aFTR_vtable_c aSumLiccaLowChest_func = {
	&aSumLiccaLowChest_ct,
	&aSumLiccaLowChest_mv,
	&aSumLiccaLowChest_dw,
	&aSumLiccaLowChest_dt,
	NULL,
};

aFTR_PROFILE iam_sum_liccalowchest = {
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	40.0f,
	0.01f,
	aFTR_SHAPE_TYPEB_0,
	mCoBG_FTR_TYPEB_0,
	0,
	0,
	0,
	aFTR_INTERACTION_STORAGE_DRAWERS,
	&aSumLiccaLowChest_func,
};
