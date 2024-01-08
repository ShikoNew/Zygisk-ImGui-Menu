#ifndef ZYCHEATS_SGUYS_FUNCTIONS_H
#define ZYCHEATS_SGUYS_FUNCTIONS_H
bool test;
bool addCurrency, freeItems, everythingUnlocked, showAllItems, addSkins;
bool isGodMode; float damageMultiplier = 0.18f;
bool isGod; int damageMultiplie = 1;
bool bypass = true;
bool nokick = true;
float jumpfloat;
float speedplayer;
bool speed;



monoString *CreateIl2cppString(const char *str) {
    monoString *(*String_CreateString)(void *instance, const char *str) = (monoString*(*)(void*, const char*)) (g_il2cppBaseMap.startAddress + string2Offset(OBFUSCATE("0x2596B20")));
    return String_CreateString(NULL, str);
}

void (*PurchaseRealMoney) (void* instance, monoString* itemId, monoString* receipt, void* callback);

struct ObscuredInt{
    int cryptoKey;
    int currentCryptoKey;
    int hiddenValue;
    bool inited;
    int fakeValue;
    bool fakeValueActive;
};

ObscuredInt (*ObscuredIntHook)(int);

void (*old_HunterControl)(void *instance);
void HunterControl(void *instance) {
    void *Hunter = *(void**)((uint64_t) instance + 0x40);
    if (test){
        *(ObscuredInt*)((uint64_t)Hunter + 0xB0) = ObscuredIntHook(99999);
    }
    return old_HunterControl(instance);
}

void Patches(){
   PATCH("0xA2F1D8", "C0035FD6");
    PATCH("0xA2F494", "C0035FD6");
    PATCH_SWITCH("0xe38d5c", "C0035FD6", bypass);
    PATCH_SWITCH("0x10e2af8", "C0035FD6", bypass);
PATCH_SWITCH("0xeb85d8", "C0035FD6", bypass);
    PATCH_SWITCH("0x10bdecc", "C0035FD6", bypass);
PATCH_SWITCH("0x10c1894", "C0035FD6", bypass);
    PATCH_SWITCH("0x18b6c04", "C0035FD6", nokick);
 PATCH_SWITCH("0x18b78e8", "C0035FD6", nokick);
    PATCH_SWITCH("0x18b7a60", "C0035FD6", nokick);
    PATCH_SWITCH("0x18ba094", "C0035FD6", nokick);
    ////
    PATCH_SWITCH("0x10A69A0", "200080D2C0035FD6", showAllItems);
    PATCH_SWITCH("0xF148A4", "E07C80D2C0035FD6", freeItems);
}


void (*old_GodMode)(void *instance);
void GodMode(void *instance) {
    if (instance != NULL) {
        if (isGod) {
            return;
        }
    }
    return old_GodMode(instance);
}
void (*old_SetSpeed)(void *instance, int damage);
void SetSpeed(void *instance, int damage) {
    if (instance != NULL) {
        damage *= damageMultiplie;
    }
    return SetSpeed(instance, damage);
}

//ammo

void (*old_get_Ammo)(void *instance, int ammo);
void get_Ammo(void *instance, int ammo) {
    if (instance != NULL) {
        ammo *= ammo1;
    }
    return get_Ammo(instance, ammo);
}
//amooo
void (*old_Backend)(void *instance);
void Backend(void *instance) {
    if (instance != NULL) {
        if (addCurrency) {
            LOGW("Calling Purchase");
            PurchaseRealMoney(instance, CreateIl2cppString("special_offer1"), CreateIl2cppString("dev"), NULL);
            addCurrency = false;
        }
        if (addSkins) {
            LOGW("Calling Skins");
            addSkins = false;
        }
    }
    return old_Backend(instance);
}

void* (*old_ProductDefinition)(void *instance, monoString* id, monoString* storeSpecificId, int type, bool enabled, void* payouts);
void* ProductDefinition(void *instance, monoString* id, monoString* storeSpecificId, int type, bool enabled, void* payouts) {
    if (instance != NULL) {
        LOGW("Called ProductDefinition! Here are the parameters:");
        LOGW("id: %s", id->getChars());
        LOGW("storeSpecificId: %s", storeSpecificId->getChars());
        LOGW("type: %i", type);
    }
    return old_ProductDefinition(instance, id, storeSpecificId, type, enabled, payouts);
}


void Hooks() {
    HOOK("0x982200", HunterControl, old_HunterControl);
    HOOK("0x982200", get_Ammo, old_get_Ammo);
    HOOK("0x12cdfd0", GodMode, old_GodMode);
    HOOK("0x12a4120", SetSpeed, old_SetSpeed);
    HOOK("0xe0c35c", Backend, old_Backend);
    HOOK("", ProductDefinition, old_ProductDefinition);
}

void Pointers() {
    PurchaseRealMoney = (void(*)(void*, monoString*, monoString*, void*)) (g_il2cppBaseMap.startAddress + string2Offset(OBFUSCATE("0x12a37fc")));
    ObscuredIntHook = (ObscuredInt(*)(int)) (g_il2cppBaseMap.startAddress + string2Offset(OBFUSCATE("0x9C8158")));
}

#endif
