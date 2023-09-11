@chcp 65001> nul
@echo off
echo -- параметры: %1 %2 %3
echo -- параметр 1: %1
echo -- параметр 2: %2
echo -- параметр 3: %3

set /A a= %1
set /A b= %2
set /A c= %3

set /A aa = %a% + %b%
echo -- %1 + %2 = %aa%

set /A ab = %a% * %b%
echo -- %1 * %2 = %ab%

set /A cb = %c% / %b%
echo -- %3 / %2 = %cb%

set /A ba = %b% - %a%
echo -- %2 - %1 = %ba%

set /A bb = (%b% - %a%)*(%a% - %b%)
echo -- (%2 - %1)*(%1 - %2) = %bb%
pause