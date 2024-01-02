%line 1+1 bootloader.asm
[section .data]
 video_buffer db 0xb8000

[section .text]
[global _start]

_start:

 mov eax, video_buffer


 mov byte [eax], 0x02
 mov byte [eax + 1], 0x00


 mov ecx, 8
 mov esi, eax
 mov edi, 'S' + ('t' << 8) + ('a' << 16) + ('r' << 24)
 mov edx, 't' + ('i' << 8) + ('n' << 16) + ('g' << 24)

 loop_start:
 mov [esi + 2], edi
 mov [esi + 3], edx
 add esi, 2
 loop loop_start


 mov eax, 5
 call sleep


 mov eax, "sys.s"
 xor ebx, ebx
 xor ecx, ecx
 int 0x80


 mov eax, 1
 xor ebx, ebx
 int 0x80

sleep:
 push ebp
 mov ebp, esp
 mov eax, 0
 mov ebx, 0
 mov ecx, [ebp + 8]
 int 0x80
 pop ebp
 ret

