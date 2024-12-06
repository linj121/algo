class FloydCycleModel:
    def __init__(self, cycleLength: int, fasterSpeed: int, slowerSpeed: int) -> None:
        self.CycleLength = cycleLength
        self.FasterSpeed = fasterSpeed
        self.SlowerSpeed = slowerSpeed

    def calcIterations(self, n: int) -> int:
        return n * self.CycleLength / (self.FasterSpeed - self.SlowerSpeed)

    def argmin(self) -> int:
        n = 1
        while self.calcIterations(n) % 1 != 0: 
            n += 1
        return n

    def getNumOfIterations(self) -> int:
        return self.calcIterations(self.argmin())