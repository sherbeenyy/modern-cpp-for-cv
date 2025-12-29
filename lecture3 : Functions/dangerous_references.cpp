#include <iostream>
#include <vector>
#include <string>
#include <memory>

// DANGEROUS EXAMPLES - These demonstrate what NOT to do!

// Example 1: DANGEROUS - Returning reference to local variable
int &getDangerousIntReference()
{
    int localVariable = 42;
    // WARNING: This is undefined behavior!
    // localVariable will be destroyed when function exits
    return localVariable; // NEVER do this!
}

// Example 2: DANGEROUS - Returning reference to parameter that's a copy
const std::string &getDangerousStringReference(std::string str)
{
    // str is a parameter passed by value (copy)
    // It will be destroyed when function exits
    return str; // DANGEROUS! str is local to this function
}

// Example 3: DANGEROUS - Returning reference to temporary
const std::vector<int> &getDangerousVectorReference()
{
    // This creates a temporary vector that's destroyed immediately
    return std::vector<int>{1, 2, 3, 4, 5}; // DANGEROUS!
}

// Example 4: DANGEROUS - Chained operations with temporaries
class MyClass
{
private:
    int value = 0;

public:
    MyClass(int v) : value(v) {}

    // This looks innocent but can be dangerous
    const MyClass &setValue(int v)
    {
        value = v;
        return *this;
    }

    int getValue() const { return value; }
};

const MyClass &getDangerousClassReference()
{
    // This creates a temporary MyClass object
    return MyClass(100).setValue(200); // DANGEROUS! Temporary object
}

// SAFE EXAMPLES - These show the correct approaches

// Safe 1: Return by value
int getSafeInt()
{
    int localVariable = 42;
    return localVariable; // Safe: returns a copy
}

// Safe 2: Return reference to parameter passed by reference
const std::string &getSafeStringReference(const std::string &str)
{
    // str exists outside this function, so it's safe to return reference
    return str; // Safe: str is not local to this function
}

// Safe 3: Return reference to static variable
int &getSafeStaticReference()
{
    static int staticVariable = 100; // Static storage duration
    return staticVariable;           // Safe: staticVariable survives function exit
}

// Safe 4: Return reference to member variable
class SafeClass
{
private:
    int memberVariable = 0;

public:
    SafeClass(int value) : memberVariable(value) {}

    // Safe: returning reference to member variable
    int &getMemberReference()
    {
        return memberVariable; // Safe: member exists as long as object exists
    }

    const int &getMemberReference() const
    {
        return memberVariable; // Safe const version
    }

    int getValue() const { return memberVariable; }
};

// Safe 5: Return smart pointer for dynamic allocation
std::unique_ptr<int> createDynamicInt(int value)
{
    return std::make_unique<int>(value); // Safe: dynamic allocation
}

// Safe 6: Return by value for complex objects
std::vector<int> createSafeVector()
{
    std::vector<int> localVector{1, 2, 3, 4, 5};
    return localVector; // Safe: move semantics will optimize this
}

// Demonstration functions to show the problems
void demonstrateDangerousCode()
{
    std::cout << "=== Demonstrating Dangerous Code ===" << std::endl;
    std::cout << "WARNING: The following examples show undefined behavior!" << std::endl;

    // This will compile but is undefined behavior
    // Uncommenting these lines might crash or give random values

    /*
    int& dangRef = getDangerousIntReference();
    std::cout << "Dangerous reference value: " << dangRef << std::endl;  // Undefined!

    const std::string& dangStringRef = getDangerousStringReference("test");
    std::cout << "Dangerous string: " << dangStringRef << std::endl;  // Undefined!

    const std::vector<int>& dangVecRef = getDangerousVectorReference();
    std::cout << "Dangerous vector size: " << dangVecRef.size() << std::endl;  // Undefined!
    */

    std::cout << "Note: Dangerous examples are commented out to prevent crashes." << std::endl;
    std::cout << "They would likely cause undefined behavior if executed." << std::endl;
    std::cout << std::endl;
}

void demonstrateSafeCode()
{
    std::cout << "=== Demonstrating Safe Code ===" << std::endl;

    // Safe: Return by value
    int safeInt = getSafeInt();
    std::cout << "Safe int value: " << safeInt << std::endl;

    // Safe: Reference to parameter
    std::string myString = "Hello World";
    const std::string &safeStringRef = getSafeStringReference(myString);
    std::cout << "Safe string reference: " << safeStringRef << std::endl;

    // Safe: Reference to static
    int &staticRef = getSafeStaticReference();
    std::cout << "Static reference value: " << staticRef << std::endl;
    staticRef = 200; // Modify the static variable
    std::cout << "Modified static reference: " << getSafeStaticReference() << std::endl;

    // Safe: Reference to member
    SafeClass safeObj(42);
    int &memberRef = safeObj.getMemberReference();
    std::cout << "Member reference value: " << memberRef << std::endl;
    memberRef = 99; // Modify through reference
    std::cout << "Modified member value: " << safeObj.getValue() << std::endl;

    // Safe: Smart pointer
    auto dynamicInt = createDynamicInt(77);
    std::cout << "Dynamic int value: " << *dynamicInt << std::endl;

    // Safe: Return complex object by value
    auto safeVector = createSafeVector();
    std::cout << "Safe vector size: " << safeVector.size() << std::endl;
    std::cout << "Safe vector elements: ";
    for (const auto &elem : safeVector)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl
              << std::endl;
}

// Example showing how modern compilers help
void compilerWarningsExample()
{
    std::cout << "=== Compiler Warnings ===" << std::endl;
    std::cout << "Modern compilers often warn about returning references to locals:" << std::endl;
    std::cout << "warning: reference to local variable 'localVariable' returned" << std::endl;
    std::cout << "Always enable compiler warnings with -Wall -Wextra!" << std::endl;
    std::cout << std::endl;
}

// Real-world example: Container access patterns
class Container
{
private:
    std::vector<int> data;

public:
    Container(std::initializer_list<int> init) : data(init) {}

    // Safe: Return reference to existing element
    int &at(size_t index)
    {
        if (index >= data.size())
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index]; // Safe: data[index] exists as long as Container exists
    }

    const int &at(size_t index) const
    {
        if (index >= data.size())
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index]; // Safe const version
    }

    // DANGEROUS: Don't do this!
    /*
    int& getFirst() {
        if (data.empty()) {
            int defaultValue = 0;
            return defaultValue;  // DANGEROUS! Local variable
        }
        return data[0];  // This part is safe
    }
    */

    // Safe alternative
    int getFirstSafe() const
    {
        return data.empty() ? 0 : data[0]; // Return by value
    }

    // Another safe alternative
    int *getFirstPtr()
    {
        return data.empty() ? nullptr : &data[0]; // Return pointer (can be null)
    }

    size_t size() const { return data.size(); }
};

void containerExample()
{
    std::cout << "=== Container Access Example ===" << std::endl;

    Container container{10, 20, 30, 40, 50};

    // Safe: Reference to existing element
    int &firstRef = container.at(0);
    std::cout << "First element: " << firstRef << std::endl;

    firstRef = 100; // Modify through reference
    std::cout << "Modified first element: " << container.at(0) << std::endl;

    // Safe: Get value safely
    int firstSafe = container.getFirstSafe();
    std::cout << "First element (safe copy): " << firstSafe << std::endl;

    // Safe: Pointer approach
    int *firstPtr = container.getFirstPtr();
    if (firstPtr)
    {
        std::cout << "First element via pointer: " << *firstPtr << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    std::cout << "Dangerous References vs Safe Alternatives" << std::endl;
    std::cout << "=========================================" << std::endl
              << std::endl;

    compilerWarningsExample();
    demonstrateDangerousCode();
    demonstrateSafeCode();
    containerExample();

    std::cout << "Key Rules to Remember:" << std::endl;
    std::cout << "1. NEVER return reference to local variables" << std::endl;
    std::cout << "2. NEVER return reference to temporary objects" << std::endl;
    std::cout << "3. NEVER return reference to parameters passed by value" << std::endl;
    std::cout << "4. OK to return reference to static/member variables" << std::endl;
    std::cout << "5. OK to return reference to parameters passed by reference" << std::endl;
    std::cout << "6. When in doubt, return by value or use smart pointers" << std::endl;
    std::cout << "7. Always enable compiler warnings (-Wall -Wextra)" << std::endl;

    return 0;
}