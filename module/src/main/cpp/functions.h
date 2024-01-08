#ifndef ZYCHEATS_SGUYS_FUNCTIONS_H
#define ZYCHEATS_SGUYS_FUNCTIONS_H
bool test;

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
}

void Hooks() {
    HOOK("0x982200", HunterControl, old_HunterControl);
}

void Pointers() {
    ObscuredIntHook = (ObscuredInt(*)(int)) (g_il2cppBaseMap.startAddress + string2Offset(OBFUSCATE("0x9C8158")));
}

#endif
