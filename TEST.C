#define      INCL_DOSFILEMGR
#define      INCL_DOS
#define      INCL_DOSDEVICES
#define      INCL_DOSDEVIOCTL
#include     <os2.h>
#include     <stdio.h>
#include     "test.h"
HFILE 	 driver_handle=0;
USHORT      err;
UCHAR        far *myptr=0;
USHORT      ActionTaken;
USHORT      rc;
ULONG        FileSize=0;
USHORT      FileAttribute;
ULONG        Reserved=0L;
UCHAR        Data1[8]={0};
UCHAR        Data2=0;
PADDR_STRUCT paddr_ptr;

unsigned short*  Return;
unsigned short cbreturn;
unsigned short*  Params;
unsigned long cbParam;
void main()
{

		  // open the driver

        if ((rc = DosOpen((PSZ) "mbeep$   ",
        &driver_handle,
        &ActionTaken,
        0,
        0,
        FILE_OPEN,
        OPEN_SHARE_DENYNONE | OPEN_ACCESS_READWRITE,
        NULL)) !=0)
		  {
                  printf("\nDosOpen failed, error = %d",rc);
                  getchar();
        	  DosExit(EXIT_PROCESS,0);
		  }
        Return=20;
        Params=50;
        rc = DosDevIOCtl(driver_handle, 0x92, 0x01,(void *) &Params,sizeof(Params),&cbParam,
                        (void *) &Return,sizeof(Return),&cbreturn);
        printf ("You sent the driver,  %u .\n", Params);
        printf ("Returned from the driver,  %d .\n", Return);
        Params=100;
        rc = DosDevIOCtl(driver_handle, 0x92, 0x01,(void *) &Params,sizeof(Params),&cbParam,
                        (void *) &Return,sizeof(Return),&cbreturn);
        printf ("You sent the driver,  %u .\n", Params);
        printf ("Returned from the driver,  %d .\n", Return);
        Params=200;
        rc = DosDevIOCtl(driver_handle, 0x92, 0x01,(void *) &Params,sizeof(Params),&cbParam,
                        (void *) &Return,sizeof(Return),&cbreturn);
        printf ("You sent the driver,  %u .\n", Params);
        printf ("Returned from the driver,  %d .\n", Return);
        if (rc)
		     printf ("DevIOCtlfailed, error code = %ld\n", rc);
	getchar();
        DosClose(driver_handle);
}
