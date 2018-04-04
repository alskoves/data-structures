@ECHO OFF

SET unit=E
SET /P unit=Insira a unidade de disco do seu dispositivo

:a                                    
::verifica e exlui todos os arquivos que NÃO ESTÃO ocultos

SET f=teste
DIR /B /A -H -S| SET /P f                         


FOR /f %%A IN ('DIR /a-d-s-h /b ^| FIND /v /c ""') DO SET cnt=%%A     
IF %A%>0 GOTO a
::se ainda houver arquivos não ocultos, volta para o começo da rotina


ATTRIB %unit%:\*.* /d /s +a -h -r -s

DEL "%unit%:\iso.vbs"
DEL "%unit%:\SystemValueInformation"

ECHO.Seus arquivos devem aparecer novamente. Obrigado por utilizar.
PAUSE
EXIT

::ver https://stackoverflow.com/questions/11004045/batch-file-counting-number-of-files-in-folder-and-storing-in-a-variable
::ver https://stackoverflow.com/questions/18658509/how-to-get-attributes-of-a-file-using-batch-file
