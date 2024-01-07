#ifndef ZYCHEATS_SGUYS_FUNCTIONS_H
#define ZYCHEATS_SGUYS_FUNCTIONS_H

// here you can define variables for the patches
bool addCurrency, freeItems, everythingUnlocked, showAllItems, addSkins;
bool isGodMode; int damageMultiplier = 1;
bool bypass = true;
bool nokick = true;
monoString *CreateIl2cppString(const char *str) {
    monoString *(*String_CreateString)(void *instance, const char *str) = (monoString*(*)(void*, const char*)) (g_il2cppBaseMap.startAddress + string2Offset(OBFUSCATE("0x2596B20")));
    return String_CreateString(NULL, str);
}

void (*PurchaseRealMoney) (void* instance, monoString* itemId, monoString* receipt, void* callback);

void Pointers() {
    PurchaseRealMoney = (void(*)(void*, monoString*, monoString*, void*)) (g_il2cppBaseMap.startAddress + string2Offset(OBFUSCATE("0xE7AADC")));
}

void Patches() {
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

// declare your hooks here

void (*old_ApplyDamagePlayer)(void *instance);
void ApplyDamagePlayer(void *instance) {
    if (instance != NULL) {
        if (isGodMode) {
            return;
        }
    }
    return old_ApplyDamagePlayer(instance);
}
void (*old_ApplyDamageEnemy)(void *instance, int damage);
void ApplyDamageEnemy(void *instance, int damage) {
    if (instance != NULL) {
        damage *= damageMultiplier;
    }
    return old_ApplyDamageEnemy(instance, damage);
}


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
    HOOK("0x12cdfd0", isGodMode, old_ApplyDamagePlayer);
    HOOK("0xE7BC74", Backend, old_Backend);
    HOOK("0x29DA08C", ProductDefinition, old_ProductDefinition);
}

#endif //ZYCHEATS_SGUYS_FUNCTIONS_H
