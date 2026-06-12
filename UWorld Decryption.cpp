#include <intrin.h>
#include <cstdint>

class UWorld
{
public:
    static inline uintptr_t get_world()
    {
        auto base = Memory->process_base();
        if (!base)
            return 0;

        uint64_t v = Memory->read<uint64_t>(base + g_world_rva);
        if (!v)
            return 0;

        v = 0xA323219E066D436DuLL * v - 0x6FA832BFC5B44018ULL;

        return static_cast<uintptr_t>(v);
    }
};
