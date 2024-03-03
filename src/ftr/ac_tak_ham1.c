static void fTHM1_ct(FTR_ACTOR* ftr_actor, u8* data);
static void fTHM1_mv(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data);
static void fTHM1_dw(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data);

static aFTR_vtable_c fTHM1_func = {
	&fTHM1_ct,
	&fTHM1_mv,
	&fTHM1_dw,
	NULL,
	NULL,
};

aFTR_PROFILE iam_tak_ham1 = {
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
	aFTR_SHAPE_TYPEA,
	mCoBG_FTR_TYPEA,
	0,
	0,
	0,
	0,
	&fTHM1_func,
};
