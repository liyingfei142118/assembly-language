    ;��ʾ����ģ����������¼��dp75.asm
        section   text
        bits   16                   ;16λ��ģʽ
        org    7C00H                ;��װ�뵽���Ϊ07C00H���ڴ�����
    Begin:
        MOV   AL, 0                 ;ָ����ʾҳ0
        MOV   AH, 5
        INT   10H                   ;ָ����ʾҳ//@1
        ;
        CLD
        MOV   AX, CS
        MOV   DS, AX                ;���ݶ�������һ��
        MOV   SI, hello             ;ָ���ַ�����
        ;
        MOV   AX, 0B800H            ;��ʾ�洢����ֵ
        MOV   ES, AX                ;�͵�ES
        MOV   DI, (80*5+8)*2        ;��ʼ��ʾ���꣺5��8��
        ;
        MOV   AH, 47H               ;���ԣ���װ��֣�
    Lab1:
        LODSB                       ;ȡһ���ַ�
        OR    AL, AL                ;�жϽ������
        JZ    Lab2                  ;�ǣ���ת����
        STOSW                       ;���ʾ�洢��
        JMP   Lab1                  ;����
    Lab2:
    Over:
        JMP   Over                  ;��������ѭ��
        ;
    hello     db    "Hello,world", 0
        ;
        times  510 - ($-$$)  db  0  ;���0��ֱ����510�ֽ�
        db    55h, 0AAh             ;���2�ֽڣ�����512�ֽ�