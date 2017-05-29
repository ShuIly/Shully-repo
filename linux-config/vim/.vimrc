call pathogen#infect()
set nocompatible
filetype off
syntax on
set runtimepath+=~/.vim/bundle/youcompleteme
filetype plugin indent on
set number

" Use case insensitive search, except when using capital letters
set ignorecase
set smartcase

filetype on
filetype plugin on
filetype indent on

set shiftwidth=3
set softtabstop=3
set expandtab

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

set hlsearch
noremap <F4> :set hlsearch! hlsearch?<CR>

set tw=80

noremap <F3> :Autoformat<CR>

let g:airline#extensions#tabline#enabled = 1
nnoremap <C-n> :bn<CR>

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0

let g:html5_event_handler_attributes_complete = 0
let g:html5_rdfa_attributes_complete = 0
let g:html5_microdata_attributes_complete = 0
let g:html5_aria_attributes_complete = 0

let g:AutoPairsMapCR = 0

" Youcompleteme C++
" let g:ycm_global_ycm_extra_conf = '.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
let g:ycm_global_ycm_extra_conf = '~/.vim/.ycm_extra_conf.py'
let g:ycm_confirm_extra_conf=0
let g:ycm_collect_identifiers_from_tags_files=1
set completeopt-=preview
let g:ycm_min_num_of_chars_for_completion=1
let g:ycm_cache_omnifunc=0
let g:ycm_seed_identifiers_with_syntax=1

" path to directory where library can be found
let g:clang_library_path='/usr/lib/llvm-4.0/lib/libclang.so.1'

" snipMate
imap <C-J> <esc>a<Plug>snipMateNextOrTrigger
smap <C-J> <Plug>snipMateNextOrTrigger

" CtrlP
noremap <C-a> :CtrlP ~/Documents/Programming/<CR>

let g:indentLine_char = '🞄'

" Instead of failing a command because of unsaved changes, instead raise a
" dialogue asking if you wish to save changed files.
set confirm

map <F9> :w<CR> :!clear; make<CR> :!./%<<CR>

syntax enable
colorscheme gruvbox
set background=dark
hi Normal ctermbg=none

