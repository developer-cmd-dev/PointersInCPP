
#include<bits/stdc++.h>
#include <thread>

using namespace std;

int main() {
    float A = 0, B = 0;
    const int width = 40, height = 40;
    const float theta_spacing = 0.07, phi_spacing = 0.02;
    const float R1 = 1, R2 = 2, K2 = 5;
    const float K1 = width * K2 * 3 / (8 * (R1 + R2));

    while (true) {
        float z[height * width];
        char output[height * width];
        memset(output, ' ', height * width);
        memset(z, 0, sizeof(z));

        for (float theta = 0; theta < 2 * M_PI; theta += theta_spacing) {
            for (float phi = 0; phi < 2 * M_PI; phi += phi_spacing) {
                float cosA = cos(A), sinA = sin(A);
                float cosB = cos(B), sinB = sin(B);
                float cosTheta = cos(theta), sinTheta = sin(theta);
                float cosPhi = cos(phi), sinPhi = sin(phi);

                float circleX = R2 + R1 * cosTheta;
                float circleY = R1 * sinTheta;

                float x = circleX * (cosB * cosPhi + sinA * sinB * sinPhi) - circleY * cosA * sinB;
                float y = circleX * (sinB * cosPhi - sinA * cosB * sinPhi) + circleY * cosA * cosB;
                float zVal = K2 + cosA * circleX * sinPhi + circleY * sinA;
                float ooz = 1 / zVal;

                int xp = (int)(width / 2 + K1 * ooz * x);
                int yp = (int)(height / 2 - K1 * ooz * y);

                int idx = xp + width * yp;
                float L = cosPhi * cosTheta * sinB - cosA * cosTheta * sinPhi - sinA * sinTheta + cosB * (cosA * sinTheta - cosTheta * sinA * sinPhi);

                if (idx >= 0 && idx < height * width) {
                    if (ooz > z[idx]) {
                        z[idx] = ooz;
                        int luminance_index = (int)(8 * L);
                        const char* luminance = ".,-~:;=!*#$@";
                        output[idx] = luminance_index > 0 ? luminance[luminance_index] : '.';
                    }
                }
            }
        }

        cout << "\x1b[H";
        for (int k = 0; k < height * width; k++) {
            cout << output[k];
            if (k % width == width - 1) cout << '\n';
        }

        A += 0.04;
        B += 0.08;

        this_thread::sleep_for(std::chrono::milliseconds(30));
    }

    return 0;
}
