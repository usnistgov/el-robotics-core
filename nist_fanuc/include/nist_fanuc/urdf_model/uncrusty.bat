
cd /d %~dp0

for %%g in (*.cpp) do (
   C:\Users\michalos\Documents\bin\uncrustify-0.59-win32\uncrustify -c C:\Users\michalos\Documents\bin\uncrustify-0.59-win32/rr.cfg   --replace %%g 
)

for %%g in (*.h) do (
   C:\Users\michalos\Documents\bin\uncrustify-0.59-win32\uncrustify -c C:\Users\michalos\Documents\bin\uncrustify-0.59-win32/rr.cfg   --replace %%g 
)

pause