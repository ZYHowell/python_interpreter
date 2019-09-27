def getAddress(line):
    return int(line[1:], 16)

system_list = []
register = [0 for i in range(32)]
register_name = ["zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0/fp", "s1", 
"a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", 
"s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", 
"t3", "t4", "t5", "t6"]

class command_t(object):
    def __init__(self):
        pass
    def run(self):
        pass
class R_type(command_t):
    def __init__(self, command):
        __data = [command[0:7], int(command[12:17], 2), int(command[7:12], 2), command[17:20], int(command[20:25], 2)]
        #func7, rs1, rs2, func3, rd
        print(register_name[__data[1]], register_name[__data[2]], register_name[__data[4]], end = ' ')
class I_type(command_t):
    def __init__(self, command):
        __data = [command[0:12], int(command[12:17], 2), command[17:20], int(command[20:25], 2)]
        #imm, rs1, func3, rd
        print(register_name[__data[1]], register_name[__data[3]], end = ' ')
class S_type(command_t):
    def __init__(self, command):
        __data = [command[0:7] + command[20:25], int(command[12:17], 2), int(command[7:12], 2), command[17:20]]
        #imm, rs1, rs2, func3
        print(register_name[__data[1]], register_name[__data[2]], end = ' ')
class U_type(command_t):
    def __init__(self, command):
        __data = [command[0:20], int(command[20:25], 2)]
        #imm, rd
        print(register_name[__data[1]], end = ' ')
class UJ_type(command_t):
    def __init__(self, command):
        __data = [command[0:1] + command[12:20] + command[11:12] + command[1:11], int(command[20:25], 2)]
        #imm, rd
        print(register_name[__data[1]], end = ' ')
class SB_type(command_t):
    def __init__(self, command):
        __data = [command[0:1] + command[24:24] + command[1:7] + command[20:24], int(command[12:17], 2), 
        int(command[7:12], 2), command[17:20]]
        #imm, rs1, rs2, func3
        print(register_name[__data[1]], register_name[__data[2]], end = ' ')


class parser_t(object):
    def __init__(self, command):
        pass
    def addcommand(self, command, address):
        try:
            print(hex(address), end = ' ')
            system_list.append([address, command_list[command[25:]](command)])
        except:
            print("command not found")
class LUI(U_type):
    def __init__(self, command):
        super().__init__(command)
        print("lui")
    def run(self):
        pass
class AUIPC(U_type):
    def __init__(self, command):
        super().__init__(command)
        print("auipc")
class JAL(UJ_type):
    def __init__(self, command):
        super().__init__(command)
        print("jal")
    def run(self):
        pass
class JALR(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("jalr")
    def run(self):
        pass
def OOZ(command):
    return OOZ_list[command[17:20]](command)
def ZZZ(command):
    return ZZZ_list[command[17:20]](command)
def ZOZ(command):
    return ZOZ_list[command[17:20]](command)
def ZZO(command):
    return ZZO_list[command[17:20]](command)
def ZOO(command):
    return ZOO_list[command[17:20]](command)

class BEQ(SB_type):
    def __init__(self, command):
        super().__init__(command)
        print("beq")
    def run(self):
        pass
class BNE(SB_type):
    def __init__(self, command):
        super().__init__(command)
        print("bne")
    def run(self):
        pass
class BLT(SB_type):
    def __init__(self, command):
        super().__init__(command)
        print("blt")
    def run(self):
        pass
class BGE(SB_type):
    def __init__(self, command):
        super().__init__(command)
        print("bge")
    def run(self):
        pass
class BLTU(SB_type):
    def __init__(self, command):
        super().__init__(command)
        print("bltu")
    def run(self):
        pass
class BGEU(SB_type):
    def __init__(self, command):
        super().__init__(command)
        print("bgeu")
    def run(self):
        pass
class LB(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("lb")
    def run(self):
        pass
class LH(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("lh")
    def run(self):
        pass
class LW(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("lw")
    def run(self):
        pass
class LBU(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("lbu")
    def run(self):
        pass
class LHU(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("lhu")
    def run(self):
        pass
class SB(SB_type):
    def __init__(self, command):
        super().__init__(command)
        print("sb")
    def run(self):
        pass
class SH(SB_type):
    def __init__(self, command):
        super().__init__(command)
        print("sh")
    def run(self):
        pass
class SW(SB_type):
    def __init__(self, command):
        super().__init__(command)
        print("sw")
    def run(self):
        pass
class ADDI(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("addi")
    def run(self):
        register[self.__data[1]] += int(self.__data[0], 2)
class SLTI(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("slti")
    def run(self):
        if register[self.__data[1]] < int(self.__data[0], 2):
            register[self.__data[3]] = 1
        else:
            register[self.__data[3]] = 0
class SLTIU(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("sltiu")
    def run(self):
        pass
class XORI(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("xori")
    def run(self):
        pass
class ORI(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("ori")
    def run(self):
        pass
class ANDI(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("andi")
    def run(self):
        pass
class SLLI(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("slli")
    def run(self):
        pass
def SRLAI(command):
    if command[1] == '0':
        return SRLI(command)
    else:
        return SRAI(command)
class SRLI(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("srli/srai")
    def run(self):
        pass
class SRAI(I_type):
    def __init__(self, command):
        super().__init__(command)
        print("srli/srai")
    def run(self):
        pass
def ADDSUB(command):
    if command[1] == '0':
        return ADD(command)
    else:
        return SUB(command)
class ADD(R_type):
    def __init__(self, command):
        super().__init__(command)
        print("add")
    def run(self):
        pass
class SUB(R_type):
    def __init__(self, command):
        super().__init__(command)
        print("sub")
    def run(self):
        pass
class SLL(R_type):
    def __init__(self, command):
        super().__init__(command)
        print("sll")
    def run(self):
        pass
class SLT(R_type):
    def __init__(self, command):
        super().__init__(command)
        print("slt")
    def run(self):
        pass
class SLTU(R_type):
    def __init__(self, command):
        super().__init__(command)
        print("sltu")
    def run(self):
        pass
class XOR(R_type):
    def __init__(self, command):
        super().__init__(command)
        print("xor")
    def run(self):
        pass
def SRLA(command):
    if command[1] == '0':
        return SRL(command)
    else:
        return SRA(command)
class SRL(R_type):
    def __init__(self, command):
        super().__init__(command)
        print("srl")
    def run(self):
        pass
class SRA(R_type):
    def __init__(self, command):
        super().__init__(command)
        print("sra")
    def run(self):
        pass
class OR(R_type):
    def __init__(self, command):
        super().__init__(command)
        print("or")
    def run(self):
        pass
class AND(R_type):
    def __init__(self, command):
        print("and")
    def run(self):
        pass

command_list = {"0110111":LUI, "0010111":AUIPC, "1101111":JAL, "1100111":JALR, 
"1100011":OOZ, "0000011":ZZZ, "0100011":ZOZ, "0010011":ZZO, "0110011":ZOO}
OOZ_list = {"000":BEQ, "001":BNE, "100":BLT, "101":BGE, "110":BLTU, "111": BGEU}
ZZZ_list = {"000":LB, "001":LH, "010":LW, "100":LBU, "101":LHU}
ZOZ_list = {"000":SB, "001":SH, "010":SW}
ZZO_list = {"000":ADDI, "010":SLTI, "011":SLTIU, "100":XORI, "110":ORI, "111":ANDI, "001":SLLI, "101":SRLAI}
ZOO_list = {"000":ADDSUB, "001":SLL, "010":SLT, "011":SLTU, "100":XOR, "101":SRLA, "110":OR, "111":AND}


with open("test.data", "r") as f:
    count = 0
    address = 0
    temp = 0
    Parser = parser_t(0)
    text = f.read()
    for x in text.split():
        if x[0] == '@':
            address = getAddress(x)
            print(address)
            continue
        address = address + 1
        temp = temp + int(x, 16) * 16 ** (count * 2)
        if count < 3:
            count = count + 1
        else:
            count = 0
            temp = bin(temp)[2:].rjust(32, '0')
            Parser.addcommand(temp, address)
            temp = 0