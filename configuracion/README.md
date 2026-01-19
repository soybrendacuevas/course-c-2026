# Configuración del Entorno C++ en en Windows (VS Code + MSYS2)
### Requisitos de Instalación
1. Instalación del Compilador (MSYS2 / MinGW-w64)
- Dado que las librerías de hilos como <thread> requieren soporte nativo, utilizaremos MSYS2.
- Descarga el instalador desde msys2.org.
Ejecuta el asistente de instalación.
- Al finalizar, abre la terminal UCRT64 e instala el toolchain ejecutando:
```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```
- Presiona Enter para confirmar la instalación de todos los paquetes.

2. Configuración de Variables de Entorno (PATH)
Para invocar al compilador desde cualquier terminal o desde VS Code:
2.1 Busca en Windows: "Editar las variables de entorno del sistema".
2.2 Ve a Variables de entorno > Variables del sistema.
2.3 Selecciona la variable Path y haz clic en Editar.
2.4 Añade una nueva entrada con la ruta: C:\msys64\ucrt64\bin.
2.5 Guarda los cambios y reinicia VS Code.

## Configuración de Visual Studio Code
Extensión oficial: Instala la extensión C/C++ de Microsoft (ms-vscode.cpptools).
Workspace: Abre la carpeta de tu proyecto para que VS Code detecte los archivos de configuración.
