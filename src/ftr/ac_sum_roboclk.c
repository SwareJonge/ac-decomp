static void aSumroboclk_ct(FTR_ACTOR* ftr_actor, u8* data);
static void aSumroboclk_mv(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data);
static void aSumroboclk_dw(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data);
static void aSumroboclk_dt(FTR_ACTOR* ftr_actor, u8* data);

static aFTR_vtable_c aSumroboclk_func = {
	&aSumroboclk_ct,
	&aSumroboclk_mv,
	&aSumroboclk_dw,
	&aSumroboclk_dt,
	NULL,
};

aFTR_PROFILE iam_sum_roboclk = {
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	18.0f,
	0.01f,
	aFTR_SHAPE_TYPEA,
	mCoBG_FTR_TYPEA,
	0,
	2,
	0,
	0,
	&aSumroboclk_func,
};