//  include file for test.c

#define  OUR_CAT  0x128             // category for DosDevIOCtl
#define  DRIVER_BASE 0xD8000         // board address
#define  BASE_LENGTH 0x1000			 // length of memory map

typedef struct _ADDR_STRUCT {
	void     far *mapped_addr;
	ULONG    board_addr;
	} ADDR_STRUCT;
typedef ADDR_STRUCT far *PADDR_STRUCT;

typedef struct        Data
  {
  short        frequency;          // Media descriptor
  short        duration;         // -1 = Changed, 0 = Unsure, 1 = Unchanged
  } DATA;

