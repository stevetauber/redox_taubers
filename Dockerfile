FROM qmkfm/qmk_firmware:latest

ARG keymap=stevetauber
ARG target_folder="./keyboards/redox/keymaps/$keymap"
ARG source_folder="./$keymap"

ENV build_keyboard="redox/rev1:default"
ENV output_hex="redox_rev1_default.hex"

VOLUME /qmk_firmware
WORKDIR /qmk_firmware

RUN mkdir -p $target_folder
COPY $source_folder $target_folder

CMD make $build_keyboard && if [ -f $output_hex ]; then echo "SUCCESS!"; fi
