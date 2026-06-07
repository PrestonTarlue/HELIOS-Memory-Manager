
#include <vector>
#include <iostream>
#include <algorithm>

class MemoryBlock 
{
    private:
        int MemoryAddress;
        int Size;
        bool isEmpty;
    public:
        MemoryBlock(int MemoryAddress, int Size): MemoryAddress(MemoryAddress), Size(Size), isEmpty(true) {}

        void initialize()
        {
            std::cout << "Memory Block initialized at address: " <<std::endl;
            std::cout<< MemoryAddress <<std::endl;
            std::cout<< " size: " << Size << std::endl;
            std::cout << "isEmpty: " << (isEmpty ? "true" : "false") << std::endl;
        }

        bool getIsEmpty() const 
        {
            return isEmpty;
        }
        int getSize() const 
        {
            return Size;
        }
        int getMemoryAddress() const 
        {
            return MemoryAddress;
        }
        void setEmpty(bool empty) 
        {
            isEmpty = empty;
        }
};

class MemoryManager 
{
    private:
        std::vector<MemoryBlock> memoryBlocks;
    public:
        void addMemoryBlock(int MemoryAddress, int Size)
        {
            MemoryBlock newBlock(MemoryAddress, Size);
            memoryBlocks.push_back(newBlock);
        }

        void initializeMemoryBlocks()
        {
            for (auto& block : memoryBlocks) 
            {
                block.initialize();
            }
        }

        void allocateMemory(int requiredSize)
        {
            auto it = std::find_if(memoryBlocks.begin(), memoryBlocks.end(), [requiredSize](const MemoryBlock& block) {
                return block.getIsEmpty() && block.getSize() >= requiredSize;
            });

            if (it != memoryBlocks.end()) 
            {
                it->setEmpty(false);
                std::cout << "Allocated " << requiredSize << " bytes at address: " << it->getMemoryAddress() << std::endl;
            } 
            else 
            {
                std::cout << "No suitable memory block found for allocation." << std::endl;
            }
        }

        void deallocateMemory(int MemoryAddress) 
        {
            auto it = std::find_if(memoryBlocks.begin(), memoryBlocks.end(), [MemoryAddress](const MemoryBlock& block) {
                return block.getMemoryAddress() == MemoryAddress;
            });

            if (it != memoryBlocks.end()) 
            {
                it->setEmpty(true);
                std::cout << "Deallocated memory at address: " << MemoryAddress << std::endl;
            } 
            else 
            {
                std::cout << "Memory block not found for deallocation." << std::endl;
            }
        }
};

int main() 
{
    MemoryManager memoryManager;
    memoryManager.addMemoryBlock(1000, 500);
    memoryManager.addMemoryBlock(2000, 300);
    memoryManager.addMemoryBlock(3000, 700);

    std::cout << "Initializing Memory Blocks:" << std::endl;
    memoryManager.initializeMemoryBlocks();

    std::cout << "\nAllocating Memory:" << std::endl;
    memoryManager.allocateMemory(200);
    memoryManager.allocateMemory(400);
    memoryManager.allocateMemory(600);

    return 0;
}