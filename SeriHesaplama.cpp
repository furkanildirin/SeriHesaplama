#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include <Windows.h>

std::vector<double> konvolüsyon(const std::vector<double>& x, const std::vector<double>& h) {
    auto baslangic_hesaplama = std::chrono::high_resolution_clock::now();

    int N = x.size();
    int M = h.size();
    std::vector<double> y(N + M - 1, 0);
    for (int n = 0; n < N + M - 1; ++n) {
        for (int k = 0; k < M; ++k) {
            if (n - k < 0 || n - k >= N) continue;
            y[n] += x[static_cast<std::vector<double, std::allocator<double>>::size_type>(n) - k] * h[k];
        }
    }

    auto bitis_hesaplama = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> hesaplama_fark = bitis_hesaplama - baslangic_hesaplama;

    std::cout << "Hesaplama süresi: " << hesaplama_fark.count() << " s\n";

    return y;
}

int main() {
    setlocale(LC_ALL, "Turkish");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-5, 5);
    int N = 1000;
    int M = 10;

    std::vector<double> x(N), h(M);
    for (int i = 0; i < N; ++i) x[i] = dis(gen);
    for (int i = 0; i < M; ++i) h[i] = dis(gen);

    std::vector<double> y = konvolüsyon(x, h);

    std::cout << "Hesaplama İşlemi Tamamlandı. Kapatmak İçin Enter Tuşuna Basınız!" << "\n";
    std::cin.get();

    return 0;
}
