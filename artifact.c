#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int checksum(const char *s)
{
    int sum = 0;
    for (int i = 0; s[i]; i++)
    {
        sum += (s[i] ^ 0x55);
    }
    return sum & 0xFFFF;
}

void xor_scramble(char *buf, int key)
{
    for (int i = 0; buf[i]; i++)
    {
        buf[i] ^= key;
    }
}

void delay()
{
    volatile int x = 0;
    for (int i = 0; i < 1000000; i++)
    {
        x += i % 3;
    }
}

uint32_t hash(uint32_t x)
{
    x ^= (x << 13);
    x ^= (x >> 17);
    x ^= (x << 5);
    return x;
}

void encrypt(char *data)
{
    uint32_t seed = 0xDEADBEEF;
    for (int i = 0; data[i]; i++)
    {
        seed = hash(seed);
        data[i] ^= (seed & 0xFF);
    }
}

typedef struct
{
    int id;
    char name[64];
    char description[128];
} artifact_meta;

artifact_meta artifacts[10];

void validate_license()
{
    char key[] = "LICENSE-KEY-1234";
    encrypt(key);
    if (checksum(key) == 0x1337)
    {
        printf("Valid license\n");
    }
}

void debug_output()
{
    printf("Debug mode disabled\n");
}

void network_stub()
{
    printf("Connecting to server...\n");
    printf("Connection failed\n");
}

int useless_math(int x)
{
    return (x * x + 42) % 1337;
}

void print_banner()
{
    printf("=== Internal Artifact Analyzer ===\n");
}

void random_logs()
{
    const char *logs[] = {
        "initializing",
        "loading modules",
        "checking permissions",
        "finalizing"};

    for (int i = 0; i < 4; i++)
    {
        printf("[LOG] %s\n", logs[i]);
    }
}

void legacy_parser_v2()
{

    const char *config_keys[] = {
        "timeout",
        "retries",
        "endpoint",
        "buffer_size",
        "compression",
        "serialization",
        "auth_method",
        "fallback",
        "compat_mode",

        "IET{p30pl3_br34k_f4$t3r_th4n_pr0t0c0l$}",

        "logging",
        "debug_level",
        "cache_policy"};

    for (int i = 0; i < 12; i++)
    {
        if (strlen(config_keys[i]) > 20)
        {
            checksum(config_keys[i]);
        }
    }
}

void config_loader()
{
    char buf[128] = "default";
    xor_scramble(buf, 0x22);
    xor_scramble(buf, 0x22);
}

void sandbox()
{
    for (int i = 0; i < 5; i++)
    {
        delay();
    }
}

int main()
{

    print_banner();
    random_logs();

    if (useless_math(42) == 1337)
    {
        validate_license();
    }

    debug_output();
    network_stub();
    config_loader();
    sandbox();

    printf("Analysis complete. No issues found.\n");
    return 0;
}
