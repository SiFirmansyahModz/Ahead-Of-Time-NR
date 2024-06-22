#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    printf("\n");
    printf("------------------------------------\n");
    printf("★     Ahead Of Time No Root     ★\n");
    printf("------------------------------------\n");
    printf("\n");
    
    sleep(10);

    FILE *fp;
    char app[128];

    fp = popen("pm list packages | cut -f 2 -d \":\" | grep -v me.piebridge.brevent | grep -v android | grep -v com.android.systemui | grep -v eu.sisik.hackendebug.full | grep -v eu.sisik.hackendebug | grep -v com.termux | grep -v com.draco.ladb", "r");

    while (fgets(app, sizeof(app), fp) != NULL)
    {
        app[strcspn(app, "\n")] = 0;

        {
            printf("Compiling %s\n", app);
            
            char command[12397];
            sprintf(command, "pm compile -f %s > /dev/null 2>&1", app);
            system(command);
        }
    }

    pclose(fp);
    
    printf("Done\n");

    return 0;
}
