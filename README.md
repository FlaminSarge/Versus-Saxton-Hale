Versus-Saxton-Hale
==================

The presuccessor of FF2(FF2 is the successor of VSH)

[![Build Status](https://travis-ci.org/WildCard65/Versus-Saxton-Hale.svg?branch=master)](https://travis-ci.org/WildCard65/Versus-Saxton-Hale)

===For first/fresh installs===
Copy the 'addons' folder to the server's 'tf/' folder.
The 'scripting' folder within is entirely unnecessary unless you are a modder or want to disable the easter boss.

===For people updating from 1.42 to 1.43===
Look through the folders inside the addons/sourcemod/ folder.

The folders necessary to be updated are:
gamedata/
plugins/

configs/, scripting/, and translations/ have not been updated.

You should never really update configs or scripting if you've changed them, as you'd be reverting them to defaults anyway.

===TO DISABLE THE EASTER BOSS===
Find the line
'#define EASTER_BUNNY_ON'
in saxtonhale.sp, delete that line, and recompile the plugin using include files from
a recent snapshot of SourceMod.
