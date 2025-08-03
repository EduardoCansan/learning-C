#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // For Windows Sleep()
// #include <unistd.h> // For Linux/Mac sleep()

#define PRODUCT_NAME_SIZE 30
#define STANDART_AMOUNT 100

typedef struct {
    int code;
    char name[PRODUCT_NAME_SIZE];
    float price;
} Product;

typedef struct {
    Product product;
    int quantity;
} Cart;

void infoProduct(Product product);
void menu();
void registerProduct();
void listProducts();
void buyProduct();
void viewCart();
Product getProductByCode(int code);
int *haveInCart(int code);
void closeOrder();

static int product_counter = 0;
static int cart_counter = 0;
static Cart cart[STANDART_AMOUNT];
static Product products[STANDART_AMOUNT];

int i;

int main() {
    menu();
    return 0;
}

void infoProduct(Product product) {
    printf("Code: %d \nName: %s \nPrice: %.2f\n", product.code, product.name, product.price);
}

void menu() {
    int option;

    printf("\n==============================\n");
    printf("========== WELCOME ===========\n");
    printf("==============================\n");
    printf("Select an option:\n");
    printf("[1] - Register Product\n");
    printf("[2] - List Products\n");
    printf("[3] - Buy Product\n");
    printf("[4] - View Cart\n");
    printf("[5] - Close Order\n");
    printf("[6] - Exit\n");

    printf("\nOption: ");
    scanf("%d", &option);
    getchar();

    switch(option) {
        case 1:
            registerProduct();
            break;
        case 2:
            listProducts();
            break;
        case 3:
            buyProduct();
            break;
        case 4:
            viewCart();
            break;
        case 5:
            closeOrder();
            break;
        case 6:
            printf("Thank you for shopping with us!\n");
            Sleep(2000);
            exit(0);
        default:
            printf("*** Invalid Option ***\n");
            Sleep(2000);
            menu();
    }
}

void registerProduct() {
    printf("\nRegister Product\n================\n");

    printf("Enter product name: ");
    fgets(products[product_counter].name, PRODUCT_NAME_SIZE, stdin);
    products[product_counter].name[strcspn(products[product_counter].name, "\n")] = '\0'; // remove newline

    printf("Enter product price: ");
    scanf("%f", &products[product_counter].price);
    getchar();

    products[product_counter].code = product_counter + 1;
    printf("Product '%s' registered successfully with code %d!\n", products[product_counter].name, products[product_counter].code);

    product_counter++;
    Sleep(2000);
    menu();
}

void listProducts() {
    if (product_counter > 0) {
        printf("\nListing Products\n================\n");
        for (i = 0; i < product_counter; i++) {
            infoProduct(products[i]);
            printf("----------------\n");
            Sleep(1000);
        }
    } else {
        printf("No products registered yet!\n");
    }
    Sleep(2000);
    menu();
}

void buyProduct() {
    if (product_counter == 0) {
        printf("No products available in the market yet!\n");
        Sleep(2000);
        menu();
        return;
    }

    printf("\nEnter the product code you want to add to the cart:\n");
    printf("========== PRODUCTS ===========\n");
    for (i = 0; i < product_counter; i++) {
        infoProduct(products[i]);
        printf("----------------\n");
        Sleep(1000);
    }

    int code;
    printf("Code: ");
    scanf("%d", &code);
    getchar();

    int found = 0;
    for (i = 0; i < product_counter; i++) {
        if (products[i].code == code) {
            found = 1;

            int *get_back = haveInCart(code);
            if (get_back[0] == 1) {
                cart[get_back[1]].quantity++;
                printf("Increased quantity of product '%s' in cart.\n", cart[get_back[1]].product.name);
            } else {
                Product p = getProductByCode(code);
                cart[cart_counter].product = p;
                cart[cart_counter].quantity = 1;
                cart_counter++;
                printf("Product '%s' added to the cart.\n", p.name);
            }
            Sleep(2000);
            menu();
            return;
        }
    }

    if (!found) {
        printf("No product found with code %d.\n", code);
        Sleep(2000);
        menu();
    }
}

void viewCart() {
    if (cart_counter > 0) {
        printf("\nCart Products\n================\n");
        for (i = 0; i < cart_counter; i++) {
            infoProduct(cart[i].product);
            printf("Quantity: %d\n", cart[i].quantity);
            printf("----------------\n");
            Sleep(1000);
        }
    } else {
        printf("No products in the cart yet!\n");
    }
    Sleep(2000);
    menu();
}

Product getProductByCode(int code) {
    for (i = 0; i < product_counter; i++) {
        if (products[i].code == code) {
            return products[i];
        }
    }
    Product empty = {0, "", 0.0};
    return empty;
}

int *haveInCart(int code) {
    static int result[2] = {0, 0};
    result[0] = 0;
    result[1] = 0;

    for (i = 0; i < cart_counter; i++) {
        if (cart[i].product.code == code) {
            result[0] = 1;
            result[1] = i;
            break;
        }
    }
    return result;
}

void closeOrder() {
    if (cart_counter == 0) {
        printf("No products in the cart yet!\n");
        Sleep(2000);
        menu();
        return;
    }

    float total_price = 0.0;
    printf("\nOrder Summary\n================\n");
    for (i = 0; i < cart_counter; i++) {
        Product p = cart[i].product;
        int quantity = cart[i].quantity;
        total_price += p.price * quantity;
        infoProduct(p);
        printf("Quantity: %d\n", quantity);
        printf("----------------\n");
        Sleep(1000);
    }

    printf("Total: $%.2f\n", total_price);
    printf("Thank you for your purchase!\n");

    cart_counter = 0;
    Sleep(5000);
    menu();
}