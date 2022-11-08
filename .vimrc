set nocompatible
colorscheme ron
syntax enable
set nu
"Useful to keep previous commands and save files make sure to create the files
set history=1000
set undofile
se undodir=~/.vim/undo/,.
set backup
set backupdir=~/.vim/backup/,.
set history=1000
set viminfo='20,\"500

"Useful info at the bottom of the screen
set ruler
set showcmd
set wildmenu
set laststatus=2 "always shows name of file
"set statusline+=%F "shows full path
set title "name on top of window

"Indent
set shiftround
set autoindent
set smartindent
set nocindent
set tabstop=4
set shiftwidth=4
set noexpandtab
set nofixendofline "removes trailing newline at EOF

"Vertical bar
set cc=80
highlight ColorColumn ctermbg=lightgrey guibg=lightgrey

" Remap F1 to update header
nn <F1> :Stdheader<CR>

" Enable or disable mouse
set mouse=""

"Remap commands
:command! WQ wq
:command! Wq wq
:command! W w
:command! Q q
inoremap <Down> <Nop>
inoremap <Up> <Nop>
inoremap <Left> <Nop>
inoremap <Right> <Nop>

"" Remove newbie crutches in Normal Mode
"nnoremap <Down> <Nop>
"nnoremap <Up> <Nop>
nnoremap <Down> <Nop>
nnoremap <Up> <Nop>
nnoremap <Left> <Nop>
nnoremap <Right> <Nop>

" Remove newbie crutches in Visual Mode
"vnoremap <Down> <Nop>
"vnoremap <Up> <Nop>
vnoremap <Left> <Nop>
vnoremap <Down> <Nop>
vnoremap <Up> <Nop>
vnoremap <Right> <Nop>

" Disable wheels
nmap <ScrollWheelUp> 
nmap <S-ScrollWheelUp> 
nmap <C-ScrollWheelUp> <nop>
nmap <ScrollWheelDown> 
nmap <S-ScrollWheelDown> 
nmap <C-ScrollWheelDown> <nop>
nmap <ScrollWheelLeft> <nop>
nmap <S-ScrollWheelLeft> <nop>
nmap <C-ScrollWheelLeft> <nop>
nmap <ScrollWheelRight> <nop>
nmap <S-ScrollWheelRight> <nop>
nmap <C-ScrollWheelRight> <nop>

imap <ScrollWheelUp> 
imap <S-ScrollWheelUp> 
imap <C-ScrollWheelUp> <nop>
imap <ScrollWheelDown> 
imap <S-ScrollWheelDown> 
imap <C-ScrollWheelDown> <nop>
imap <ScrollWheelLeft> <nop>
imap <S-ScrollWheelLeft> <nop>
imap <C-ScrollWheelLeft> <nop>
imap <ScrollWheelRight> <nop>
imap <S-ScrollWheelRight> <nop>
imap <C-ScrollWheelRight> <nop>

vmap <ScrollWheelUp> <nop>
vmap <S-ScrollWheelUp> <nop>
vmap <C-ScrollWheelUp> <nop>
vmap <ScrollWheelDown> <nop>
vmap <S-ScrollWheelDown> <nop>
vmap <C-ScrollWheelDown> <nop>
vmap <ScrollWheelLeft> <nop>
vmap <S-ScrollWheelLeft> <nop>
vmap <C-ScrollWheelLeft> <nop>
vmap <ScrollWheelRight> <nop>
vmap <S-ScrollWheelRight> <nop>
vmap <C-ScrollWheelRight> <nop>
