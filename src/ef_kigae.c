#include "ef_effect_control.h"

static void eKigae_init(xyz_t pos, int prio, s16 angle, GAME* game, u16 item_name, s16 arg0, s16 arg1);
static void eKigae_ct(eEC_Effect_c* effect, GAME* game, void* ct_arg);
static void eKigae_mv(eEC_Effect_c* effect, GAME* game);
static void eKigae_dw(eEC_Effect_c* effect, GAME* game);

eEC_PROFILE_c iam_ef_kigae = {
    // clang-format off
    &eKigae_init,
    &eKigae_ct,
    &eKigae_mv,
    &eKigae_dw,
    eEC_IGNORE_DEATH,
    eEC_NO_CHILD_ID,
    eEC_DEFAULT_DEATH_DIST,
    // clang-format on
};

static void eKigae_init(xyz_t pos, int prio, s16 angle, GAME* game, u16 item_name, s16 arg0, s16 arg1) {
    // TODO
}

static void eKigae_ct(eEC_Effect_c* effect, GAME* game, void* ct_arg) {
    // TODO
}

static void eKigae_mv(eEC_Effect_c* effect, GAME* game) {
    // TODO
}

static void eKigae_dw(eEC_Effect_c* effect, GAME* game) {
    // TODO
}
