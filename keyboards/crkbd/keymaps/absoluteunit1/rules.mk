LEADER_ENABLE = yes
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

# sentence case
SRC += features/sentence_case.c

# vim case (note that the order is important here)
SRC += qmk-vim/src/mac_mode.c
SRC += qmk-vim/src/process_func.c
SRC += qmk-vim/src/numbered_actions.c
SRC += qmk-vim/src/motions.c
SRC += qmk-vim/src/actions.c
SRC += qmk-vim/src/modes.c
SRC += qmk-vim/src/vim.c


