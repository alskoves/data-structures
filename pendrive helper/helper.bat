@ECHO OFF

SET unit=E
SET /P unit=Insira a unidade de disco do seu dispositivo



ATTRIB %unit%:\*.* /d /s +a -h -r -s

DEL "%unit%:\iso.vbs"
DEL "%unit%:\SystemValueInformation"

ECHO."Seus arquivos devem aparecer novamente. Obrigado por utilizar.

EXIT
