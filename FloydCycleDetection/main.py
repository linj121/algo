from model import FloydCycleModel 

if __name__ == "__main__":
    
    floydCycle = FloydCycleModel(4, 2, 1)

    print(floydCycle.getNumOfIterations())