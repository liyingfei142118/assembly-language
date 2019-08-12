    ;演示程序（工作程序）dp78.asm
        section   text
        bits   16
    ;工作程序特征信息
    Signature     db   "YANG"       ;签名信息
    Version       dw   1            ;格式版本
    Length        dw   end_of_text  ;工作程序长度
    Start         dw   Begin        ;工作程序入口点的偏移
    Zoneseg       dw   0088H        ;工作程序期望的内存区域起始段值
    Reserved      dd   0            ;保留
    ;-------------------------------
    ;数据部分之一
    info   db    "Address:", 0      ;提示信息
    ;-------------------------------
    ;代码部分
    Begin:                          ;工作程序入口
        MOV   AX, CS
        MOV   DS, AX                ;源数据段与代码段一致
        CLD                         ;清方向标志
        MOV   DX, info
        CALL  PutStr                ;显示提示信息
        ;
        MOV   DX, CS                ;准备显示工作内存区域的段值
        MOV   CX, 4                 ;4位十六进制数
        MOV   SI, buffer            ;字符串缓冲区首地址
    Next:
        ROL   DX, 4                 ;循环左移4位
        MOV   AL, DL                ;
        CALL  TOASCII               ;转换成对应ASCII码
        MOV   [SI],AL               ;依次填到缓冲区
        INC   SI
        LOOP  Next                  ;下一位
        ;
        MOV   DX, buffer            ;取得显示字符串首地址
        CALL  PutStr                ;显示之
        ;
        JMP  Begin1                       ;返回到加载程序!!//@1
    ;-------------------------------
    PutStr:                         ;显示字符串（以0结尾）
        MOV   BH, 0
        MOV   SI, DX                ;DX=字符串起始地址偏移
    .LAB1:
        LODSB
        OR    AL, AL
        JZ    .LAB2
        MOV   AH, 14
        INT   10H
        JMP   .LAB1
    .LAB2:
        RET
    ;
    TOASCII:                        ;转对应十六进制数的ASCII码
        AND   AL, 0FH               ;AL低4位 = 十六进制数
        ADD   AL, '0'
        CMP   AL, '9'
        SETBE BL
        DEC   BL
        AND   BL, 7
        ADD   AL, BL
        RET

Begin1:
        MOV   AL, 0                 ;指定显示页0
        MOV   AH, 5
        INT   10H                   ;指定显示页//@1
        ;
        CLD
        MOV   AX, CS
        MOV   DS, AX                ;数据段与代码段一致
        MOV   SI, hello             ;指向字符串首
        ;
        MOV   AX, 0B800H            ;显示存储区段值
        MOV   ES, AX                ;送到ES
        MOV   DI, (80*5+8)*2        ;开始显示坐标：5行8列
        ;
        MOV   AH, 47H               ;属性（红底白字）
    Lab11:
        LODSB                       ;取一个字符
        OR    AL, AL                ;判断结束标记
        JZ    Lab22                  ;是，跳转结束
        STOSW                       ;填到显示存储区
        JMP   Lab11                  ;继续
    Lab22:
    Over11:
        JMP   Over11                  ;进入无限循环
        ;
    hello     db    "Hello,world", 0
        ;
        ;times  510 - ($-$$)  db  0  ;填充0，直到满510字节
        ;db    55h, 0AAh             ;最后2字节，共计512字节
    ;-------------------------------
    ;数据部分之二
           times  1024  db  90H     ;为了演示，刻意插入了1024字节
    ;
    buffer db    "00000H"           ;用于存放工作内存区域的地址
           db    0DH, 0AH, 0
    end_of_text:                    ;代码结束处（代码字节长度）
