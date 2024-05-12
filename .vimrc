set encoding=utf-8
set nocompatible
filetype off

" Plugin list used in Vim. Vundle is used here
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'kentarosasaki/vim-emacs-bindings'
Plugin 'rafi/awesome-vim-colorschemes'
Plugin 'bkbncn/vim-colorschemes-picker'
Plugin 'VundleVim/Vundle.vim'
Plugin 'flazz/vim-colorschemes'
Plugin 'honza/vim-snippets'
Plugin 'SirVer/ultisnips'
Plugin 'morhetz/gruvbox'
Plugin 'vim-utils/vim-man'
Plugin 'ojroques/vim-oscyank'
Plugin 'tpope/vim-dispatch'
Plugin 'tpope/vim-commentary'
Plugin 'preservim/nerdcommenter'
Plugin 'preservim/nerdtree'
Plugin 'neoclide/coc.nvim'
Plugin 'christoomey/vim-run-interactive'
Plugin 'ryanoasis/vim-devicons'
Plugin 'PhilRunninger/nerdtree-visual-selection'
Plugin 'gabrielsimoes/cfparser.vim'
Plugin 'lervag/vimtex'
Plugin 'dart-lang/dart-vim-plugin'
call vundle#end()

" When entering vim set colorscheme to onedark
autocmd vimenter * ++nested colorscheme gruvbox
filetype plugin indent on
filetype plugin on
" View absolute line numbers in the text file
" set number
set relativenumber
set makeprg=build.sh\ %:r
autocmd filetype cpp  nnoremap <F10> :w <bar> Make <CR>
" autocmd filetype cpp nnoremap <F8> :vertical terminal ++shell ++cols=40 ./%:r<CR>
autocmd filetype cpp nnoremap <F7> :!./%:r<CR>
" map <F7> :!./%< <CR>
map <F8> :w <CR> :!gcc % -lm -o %< && ./%< <CR>
map <F5> :CSnext<CR>

"vnoremap <C-C> :w !xsel -b<CR><CR>

set tabstop=2
set shiftwidth=2 smarttab
set softtabstop=4
set expandtab
set autoindent
set mouse=a
set ruler
set background=dark

" autocmd BufNewFile *.c 0r ~/.vim/templates/cbasic.c
" autocmd BufWinEnter *.c call cursor(9,2)
autocmd BufNewFile *.cpp 0r ~/repo/dotfiles/.vim/templates/cbasic2.cpp
autocmd BufWinEnter *.cpp call cursor(19,3)

augroup Vimrc
	autocmd!
augroup END
function Hi()
	hi Comment cterm=italic
endfunction
syntax on
autocmd Vimrc colorscheme * call Hi()
let &t_ut=''

set t_Co=256

let g:UltiSnipsExpandTrigger="<F2>"
let g:UltiSnipsJumpForwardTrigger="<c-f>"
let g:UltiSnipsJumpBackwardTrigger="<c-b>"
" May need for Vim (not Neovim) since coc.nvim calculates byte offset by count
" utf-8 byte sequence
set encoding=utf-8
" Some servers have issues with backup files, see #649
set nobackup
set nowritebackup

" Having longer updatetime (default is 4000 ms = 4s) leads to noticeable
" delays and poor user experience
set updatetime=300

" Always show the signcolumn, otherwise it would shift the text each time
" diagnostics appear/become resolved
set signcolumn=yes

" Use tab for trigger completion with characters ahead and navigate
" NOTE: There's always complete item selected by default, you may want to enable
" no select by `"suggest.noselect": true` in your configuration file
" NOTE: Use command ':verbose imap <tab>' to make sure tab is not mapped by
" other plugin before putting this into your config
" Copy to system clipboard
nmap <leader>c <Plug>OSCYankOperator
nmap <leader>cc <leader>c__
vmap <leader>c <Plug>OSCYankVisual

set laststatus=2
set numberwidth=2

" Open NERDTree File Explorer
nmap <leader>n :NERDTree<CR>

"Copied from geothermal
map <C-a> <esc>ggVG<CR>

" easier split navigations
nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>

" more natural split opening
set splitbelow
set splitright

"resizing splits 
" max out the height of the current split
" ctrl + w _
" max out the width of the current split
" ctrl + w |

" normalize all split sizes
" ctrl + w =

" setlocal spell spelllang=en_us

" Enable folding
set foldmethod=manual
set foldlevel=99
