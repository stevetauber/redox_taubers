# Readme


Use this command in order to generate a hex file. Next use qmk toolkit to flash to the device.

```
( FIRMWARE=redox_rev1_taubers.hex; docker run -it -e build_keyboard="redox/rev1:taubers" -e output_hex=$FIRMWARE $(docker build -q .) && docker cp $(docker ps -alq):/qmk_firmware/$FIRMWARE . )
```
