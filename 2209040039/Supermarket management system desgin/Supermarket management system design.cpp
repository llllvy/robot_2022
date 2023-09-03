#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Product {
public:
    int product_id;
    string product_name;
    double cost_price;
    double selling_price;
    int daily_sales;
    int stock;
    string producer;

    Product(int id, string name, double cost, double selling, int sales, int stock, string producer) {
        product_id = id;
        product_name = name;
        cost_price = cost;
        selling_price = selling;
        daily_sales = sales;
        this->stock = stock;
        this->producer = producer;
    }
};

class Supermarket {
private:
    vector<Product> products;

public:
    void add_product(Product product) {
        products.push_back(product);
    }

    Product* search_by_id(int product_id) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].product_id == product_id) {
                return &products[i];
            }
        }
        return nullptr;
    }

    Product* search_by_name(string product_name) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].product_name == product_name) {
                return &products[i];
            }
        }
        return nullptr;
    }

    void sort_by_selling_price() {
        sort(products.begin(), products.end(), [](const Product& p1, const Product& p2) {
            return p1.selling_price > p2.selling_price;
            });
    }

    void sort_by_daily_sales() {
        sort(products.begin(), products.end(), [](const Product& p1, const Product& p2) {
            return p1.daily_sales > p2.daily_sales;
            });
    }

    bool delete_product(int product_id) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].product_id == product_id) {
                products.erase(products.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool modify_product(int product_id, Product new_product) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].product_id == product_id) {
                products[i] = new_product;
                return true;
            }
        }
        return false;
    }

    double daily_profit_analysis() {
        double total_profit = 0;
        for (const auto& product : products) {
            double profit = (product.selling_price - product.cost_price) * product.daily_sales;
            total_profit += profit;
        }
        return total_profit;
    }

    void print_product_info() {
        for (const auto& product : products) {
            cout << "������: " << product.product_id << endl;
            cout << "��������: " << product.product_name << endl;
            cout << "����: " << product.cost_price << endl;
            cout << "���ۼ�: " << product.selling_price << endl;
            cout << "��������: " << product.daily_sales << endl;
            cout << "���: " << product.stock << endl;
            cout << "������: " << product.producer << endl;
            cout << endl;
        }
    }
};

int main() {
    Supermarket supermarket;

    // �����Ʒ�ļ�¼
    Product p1(1, "��Ʒ1", 10.0, 20.0, 100, 50, "������1");
    Product p2(2, "��Ʒ2", 15.0, 25.0, 80, 60, "������2");
    supermarket.add_product(p1);
    supermarket.add_product(p2);

    // ��ѯ��Ʒ
    Product* product = supermarket.search_by_id(1);
    if (product != nullptr) {
        cout << "��ѯ������������� - " << product->product_name << endl;
    }
    else {
        cout << "δ�ҵ�����Ʒ" << endl;
    }

    // ����Ʒ��������
    supermarket.sort_by_selling_price();
    cout << "�����ۼ۽�����������Ʒ��Ϣ��" << endl;
    supermarket.print_product_info();

    // ɾ����Ʒ��¼
    bool deleted = supermarket.delete_product(2);
    if (deleted) {
        cout << "��Ʒ��¼ɾ���ɹ�" << endl;
    }
    else {
        cout << "δ�ҵ�Ҫɾ������Ʒ��¼" << endl;
    }

    // �޸���Ʒ��¼
    Product new_product(1, "����Ʒ1", 8.0, 18.0, 120, 40, "��������1");
    bool modified = supermarket.modify_product(1, new_product);
    if (modified) {
        cout << "��Ʒ��¼�޸ĳɹ�" << endl;
    }
    else {
        cout << "δ�ҵ�Ҫ�޸ĵ���Ʒ��¼" << endl;
    }

    // ������ӯ������
    double profit = supermarket.daily_profit_analysis();
    cout << "������ӯ���ܶ" << profit << endl;

    // �����Ʒ��Ϣ��
    cout << "��Ʒ��Ϣ��" << endl;
    supermarket.print_product_info();

    return 0;
}