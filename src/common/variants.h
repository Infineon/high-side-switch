#include <stdint.h>

typedef struct
{
    const uint16_t kilis;
    float ampsGain;
    float ampsOffset;
    float vBatGain;
    float vBatOffset;
}BtsVariants_t;

extern BtsVariants_t BTS7002;
extern BtsVariants_t BTS7004;
extern BtsVariants_t BTS7006;
extern BtsVariants_t BTS7008;

