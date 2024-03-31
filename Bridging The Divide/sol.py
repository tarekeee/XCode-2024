from enum import Enum

src = input()

# tokenizer
TokenType = Enum("Token",["Sym","BooleanOp","TernaryOp","OPara","CPara"])
skipables = [" ","\n","\t"]
class Token:
    def __init__(self,typ,val) -> None:
        self.typ = typ
        self.val = val
    def __str__(self) -> str:
        return f"<Token typ={self.typ} val={self.val}>"
    def __repr__(self) -> str:
        return self.__str__()
class Tokenizer:
    def __init__(self) -> None:
        pass
    def tokenize(self,src):
        self.idx = 0
        self.src = src
        self.tknz = []

        while self.idx < len(self.src):
            chr = self.src[self.idx]
            self.idx += 1
            
            
            if chr in "&|": 
                self.tknz.append(Token(TokenType.BooleanOp,chr))
            elif chr in "~":
                self.tknz.append(Token(TokenType.TernaryOp,chr))
            elif chr in "()":
                if chr == "(": self.tknz.append(Token(TokenType.OPara,chr))
                else: self.tknz.append(Token(TokenType.CPara,chr))
            elif chr.isalpha():
                self.tknz.append(Token(TokenType.Sym,chr))
            elif chr in skipables:
                pass
            else:
                print("[Error] unexpected token " + chr)
                exit(-1)     
        return self.tknz           
# parser
class Expr:
    def __init__(self) -> None:
        pass
    def __str__(self) -> str:
        return f"<Expr>"
    def __repr__(self) -> str:
        return self.__str__()    
class Tree(Expr):
    def __init__(self) -> None:
        super().__init__()
        self.body = []
    def __str__(self) -> str:
        return f"<Tree body={self.body}>"        
class ParaExpr(Expr):
    def __init__(self,expr) -> None:
        super().__init__()
        self.expr = expr
    def __str__(self) -> str:
        return f"<ParaExpr expr={self.expr}>"        
class BooleanOpExpr(Expr):
    def __init__(self,op,left,right) -> None:
        super().__init__()
        self.left = left
        self.right = right
        self.op = op
    def __str__(self) -> str:
        return f"<BooleanOpExpr op={self.op} left={self.left} right={self.right}>"        
class TernaryOpExpr(Expr):
    def __init__(self,op,right) -> None:
        super().__init__()
        self.right = right
        self.op = op    
    def __str__(self) -> str:
        return f"<TernaryOpExpr op={self.op} right={self.left}>"        
class Literal(Expr):
    def __init__(self,val) -> None:
        super().__init__()
        self.val = val
    def __str__(self) -> str:
        return f"<Literal val={self.val}>"        
class Parser:
    def __init__(self) -> None:
        self.tokenizer = Tokenizer()
        self.tree = None
    
    def expect(self,typ):
        if self.tknz[self.idx].typ != typ:
            print(f"[Error] expected {typ} got {self.tknz[self.idx].typ}")
            exit(-1)
        
    def parse(self,src):
        self.idx = 0
        self.tknz = self.tokenizer.tokenize(src)
        self.tree = Tree()
        
        while self.idx < len(self.tknz):
            self.tree.body.append(self.parse_ternary_op())
    

    def parse_ternary_op(self):
        if self.tknz[self.idx].typ == TokenType.TernaryOp:
            op = self.tknz[self.idx].val; self.idx += 1
            right = self.parse_ternary_op()
            return TernaryOpExpr(op,right)
        return self.parse_boolean_op()
    def parse_boolean_op(self):
        left = self.parse_para()
        if self.idx < len(self.tknz) and self.tknz[self.idx].typ == TokenType.BooleanOp:
            op = self.tknz[self.idx].val; self.idx += 1            
            right = self.parse_ternary_op()
            return BooleanOpExpr(op,left,right)
        return left
    def parse_para(self):
        if self.idx < len(self.tknz) and self.tknz[self.idx].typ == TokenType.OPara:
            self.idx += 1
            expr = self.parse_ternary_op()
            self.expect(TokenType.CPara); self.idx += 1
            return ParaExpr(expr)
        return self.parse_literal()    
    def parse_literal(self):
        tkn = self.tknz[self.idx]
        self.idx += 1
        return Literal(tkn.val)
    
    def print_tree(self,node,depth=0):
        typ = node.__class__.__name__ 
        iden = "   " * depth 
        if typ == "Tree":
            print(iden + typ)
            for snode in node.body:
                self.print_tree(snode,depth + 1)
        elif typ == "ParaExpr":
            print(iden + typ)
            self.print_tree(node.expr,depth+1)
        elif typ == "TernaryOpExpr":
            print(iden + typ + " " + node.op)
            self.print_tree(node.right,depth+1)
        elif typ == "BooleanOpExpr":
            print(iden + typ + " op: " + node.op)
            self.print_tree(node.left,depth+1)
            self.print_tree(node.right,depth+1)
        elif typ == "Literal":
            print(iden + node.val)
        else:
            print("[Error] unexpected node")
            exit(-1)


parser = Parser()
parser.parse(src)
# parser.print_tree(parser.tree)


def h_tree(node):
    typ = node.__class__.__name__ 
    if typ == "Tree":
        hs = []
        for snode in node.body:
            hs.append(h_tree(snode))
        return max(hs) 
    elif typ == "ParaExpr":
        return h_tree(node.expr)
    elif typ == "TernaryOpExpr":
        return h_tree(node.right) + 1
    elif typ == "BooleanOpExpr":
        return max(h_tree(node.left),h_tree(node.right)) + 1
    elif typ == "Literal":
        return 0
print(f"height is {h_tree(parser.tree)}")
