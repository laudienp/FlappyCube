all:
	gcc .\src\main.c .\src\player.c .\src\pipe.c .\src\sound.c -I include -L lib -lraylibdll -o bin\main.exe

web:
	emcc -o .\bin\web\index.html .\src\main.c .\src\player.c .\src\pipe.c .\src\sound.c -Os -Wall .\lib\web\libraylib.a -I include -s USE_GLFW=3 -s ASYNCIFY --shell-file minshell.html -DPLATFORM_WEB --preload-file .\resources