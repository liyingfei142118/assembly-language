    ;��ʾ����ģ����������¼��dp74.asm
        section   text
        bits   16                   ;16λ��ģʽ
    Begin:                          ;������
        MOV   BH, 0                 ;ָ����ʾҳ0
        MOV   DH, 5                 ;����кţ�5�У�
        MOV   DL, 8                 ;����кţ�8�У�
        MOV   AH, 2                 ;2�Ź������ù��λ��
        INT   10H                   ;��λ��굽ָ��λ��
        ;
        CLD                         ;�ַ�����������
        MOV   AX, CS
        MOV   DS, AX                ;���ݶ�������һ��
        MOV   SI, hello             ;ָ���ַ����ף�����ε���Ե�ַ��
        ADD   SI, 7C00H             ;ָ���ַ����ף��ڴ��еĹ̶���ַ��//@1
    Lab1:
        LODSB                       ;ȡһ���ַ�
        OR    AL, AL                ;�жϽ������
        JZ    Lab2                  ;�ǣ���ת����
        MOV   AH, 14
        INT   10H                   ;TTY��ʽ��ʾ�ַ�
        JMP   SHORT Lab1            ;����
    Lab2:
    Over:
        JMP   Over                  ;��������ѭ��
        ;
    hello     db    "Hello,world", 0
        ;
        times  510 - ($-$$)  db  0  ;���0��ֱ����510�ֽ�
        db    55h, 0aah             ;���2�ֽڣ�����512�ֽ�