1.当16位需要乘以10000h时，只需将其移至高位寄存器
2.解决除法溢出
   H     16位高位
   L     16位低位
   N     16位除数
    INT() YU() 示意求商，求余
    K/N = INT(H/N)*10000H+(YU(H/N)*10000H+L)/N