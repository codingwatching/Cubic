#include "Skybox.h"
#include "Level.h"
#include "Game.h"
#include "TextureManager.h"
#include "Resources.h"

#include <vector>

void Skybox::init()
{
	initBedrock();
	initWater();
    initClouds();
    initSky();
}

void Skybox::initBedrock()
{
    bedrockTexture = game.textureManager.load(bedrockResourceTexture, sizeof(bedrockResourceTexture));
    bedrockVertices.init();

    const float ground = (float)game.level.groundLevel;
    int a = glm::min(128, glm::min(Level::WIDTH, Level::DEPTH));
    int b = 1024 / a;

    for (int i = -a * b; i < Level::WIDTH + a * b; i += a)
    {
        for (int j = -a * b; j < Level::DEPTH + a * b; j += a)
        {
            float g = ground;
            if (i >= 0 && j >= 0 && i < Level::WIDTH && j < Level::DEPTH) { g = 0; }

            bedrockVertices.push(VertexList::Vertex(i, g, j, 0.0f, 0.0f, 0.5f));
            bedrockVertices.push(VertexList::Vertex(i, g, j + a, 0.0f, a, 0.5f));
            bedrockVertices.push(VertexList::Vertex(i + a, g, j + a, a, a, 0.5f));

            bedrockVertices.push(VertexList::Vertex(i, g, j, 0.0f, 0.0f, 0.5f));
            bedrockVertices.push(VertexList::Vertex(i + a, g, j + a, a, a, 0.5f));
            bedrockVertices.push(VertexList::Vertex(i + a, g, j, a, 0.0f, 0.5f));
        }
    }

    for (int i = 0; i < Level::WIDTH; i += a)
    {
        bedrockVertices.push(VertexList::Vertex(i, ground, 0.0f, 0.0f, ground, 0.8f));
        bedrockVertices.push(VertexList::Vertex(i, 0.0f, 0.0f, 0.0f, 0.0f, 0.8f));
        bedrockVertices.push(VertexList::Vertex(i + a, 0.0f, 0.0f, a, 0.0f, 0.8f));

        bedrockVertices.push(VertexList::Vertex(i, ground, 0.0f, 0.0f, ground, 0.8f));
        bedrockVertices.push(VertexList::Vertex(i + a, 0.0f, 0.0f, a, 0.0f, 0.8f));
        bedrockVertices.push(VertexList::Vertex(i + a, ground, 0.0f, a, ground, 0.8f));

        bedrockVertices.push(VertexList::Vertex(i + a, ground, Level::DEPTH, a, ground, 0.8f));
        bedrockVertices.push(VertexList::Vertex(i + a, 0.0f, Level::DEPTH, a, 0.0f, 0.8f));
        bedrockVertices.push(VertexList::Vertex(i, 0.0f, Level::DEPTH, 0.0f, 0.0f, 0.8f));

        bedrockVertices.push(VertexList::Vertex(i + a, ground, Level::DEPTH, a, ground, 0.8f));
        bedrockVertices.push(VertexList::Vertex(i, 0.0f, Level::DEPTH, 0.0f, 0.0f, 0.8f));
        bedrockVertices.push(VertexList::Vertex(i, ground, Level::DEPTH, 0.0f, ground, 0.8f));
    }

    for (int i = 0; i < Level::DEPTH; i += a)
    {
        bedrockVertices.push(VertexList::Vertex(0.0f, ground, i + a, a, 0.0f, 0.6f));
        bedrockVertices.push(VertexList::Vertex(0.0f, 0.0f, i + a, a, ground, 0.6f));
        bedrockVertices.push(VertexList::Vertex(0.0f, 0.0f, i, 0.0f, ground, 0.6f));

        bedrockVertices.push(VertexList::Vertex(0.0f, ground, i + a, a, 0.0f, 0.6f));
        bedrockVertices.push(VertexList::Vertex(0.0f, 0.0f, i, 0.0f, ground, 0.6f));
        bedrockVertices.push(VertexList::Vertex(0.0f, ground, i, 0.0f, 0.0f, 0.6f));

        bedrockVertices.push(VertexList::Vertex(Level::WIDTH, ground, i, 0.0f, 0.0f, 0.6f));
        bedrockVertices.push(VertexList::Vertex(Level::WIDTH, 0.0f, i, 0.0f, ground, 0.6f));
        bedrockVertices.push(VertexList::Vertex(Level::WIDTH, 0.0f, i + a, a, ground, 0.6f));

        bedrockVertices.push(VertexList::Vertex(Level::WIDTH, ground, i, 0.0f, 0.0f, 0.6f));
        bedrockVertices.push(VertexList::Vertex(Level::WIDTH, 0.0f, i + a, a, ground, 0.6f));
        bedrockVertices.push(VertexList::Vertex(Level::WIDTH, ground, i + a, a, 0.0f, 0.6f));
    }

    bedrockVertices.update();
}

void Skybox::initWater()
{
    waterTexture = game.textureManager.load(waterResourceTexture, sizeof(waterResourceTexture));
    waterVertices.init();

    const float water = (float)game.level.waterLevel;
    int a = glm::min(128, glm::min(Level::WIDTH, Level::DEPTH));
    int b = 1024 / a;

    for (int i = -a * b; i < Level::WIDTH + a * b; i += a)
    {
        for (int j = -a * b; j < Level::DEPTH + a * b; j += a)
        {
            float w = water - 0.1f;

            if (i < 0 || j < 0 || i >= Level::WIDTH || j >= Level::DEPTH)
            {
                waterVertices.push(VertexList::Vertex(i, w, j, 0.0f, 0.0f, 1.0f));
                waterVertices.push(VertexList::Vertex(i, w, j + a, 0.0f, a, 1.0f));
                waterVertices.push(VertexList::Vertex(i + a, w, j + a, a, a, 1.0f));

                waterVertices.push(VertexList::Vertex(i, w, j, 0.0f, 0.0f, 1.0f));
                waterVertices.push(VertexList::Vertex(i + a, w, j + a, a, a, 1.0f));
                waterVertices.push(VertexList::Vertex(i + a, w, j, a, 0.0f, 1.0f));

                waterVertices.push(VertexList::Vertex(i, w, j + a, 0.0f, a, 1.0f));
                waterVertices.push(VertexList::Vertex(i, w, j, 0.0f, 0.0f, 1.0f));
                waterVertices.push(VertexList::Vertex(i + a, w, j, a, 0.0f, 1.0f));

                waterVertices.push(VertexList::Vertex(i, w, j + a, 0.0f, a, 1.0f));
                waterVertices.push(VertexList::Vertex(i + a, w, j, a, 0.0f, 1.0f));
                waterVertices.push(VertexList::Vertex(i + a, w, j + a, a, a, 1.0f));
            }
        }
    }

    waterVertices.update();
}

void Skybox::initClouds()
{
    cloudsTexture = game.textureManager.load(cloudsResourceTexture, sizeof(cloudsResourceTexture));
    cloudsVertices.init();

    float y = Level::HEIGHT + 2.0f;
    float t = 0.0f;

    for (int x = -1024; x < Level::WIDTH + 1024; x += 512)
    {
        for (int z = -1024; z < Level::DEPTH + 1024; z += 512)
        {
            cloudsVertices.push(VertexList::Vertex(x, y, z, (x + t) / 2048.0f, z / 2048.0f, 1.0f));
            cloudsVertices.push(VertexList::Vertex(x, y, z + 512, (x + t) / 2048.0f, (z + 512) / 2048.0f, 1.0f));
            cloudsVertices.push(VertexList::Vertex(x + 512, y, z + 512, (x + 512 + t) / 2048.0f, (z + 512) / 2048.0f, 1.0f));

            cloudsVertices.push(VertexList::Vertex(x, y, z, (x + t) / 2048.0f, z / 2048.0f, 1.0f));
            cloudsVertices.push(VertexList::Vertex(x + 512, y, z + 512, (x + 512 + t) / 2048.0f, (z + 512) / 2048.0f, 1.0f));
            cloudsVertices.push(VertexList::Vertex(x + 512, y, z, (x + 512 + t) / 2048.0f, z / 2048.0f, 1.0f));

            cloudsVertices.push(VertexList::Vertex(x, y, z + 512, (x + t) / 2048.0f, (z + 512) / 2048.0f, 1.0f));
            cloudsVertices.push(VertexList::Vertex(x, y, z, (x + t) / 2048.0f, z / 2048.0f, 1.0f));
            cloudsVertices.push(VertexList::Vertex(x + 512, y, z, (x + 512 + t) / 2048.0f, z / 2048.0f, 1.0f));

            cloudsVertices.push(VertexList::Vertex(x, y, z + 512, (x + t) / 2048.0f, (z + 512) / 2048.0f, 1.0f));
            cloudsVertices.push(VertexList::Vertex(x + 512, y, z, (x + 512 + t) / 2048.0f, z / 2048.0f, 1.0f));
            cloudsVertices.push(VertexList::Vertex(x + 512, y, z + 512, (x + 512 + t) / 2048.0f, (z + 512) / 2048.0f, 1.0f));
        }
    }

    cloudsVertices.update();
}

void Skybox::initSky()
{
    skyTexture = game.textureManager.generateSolidColor(0.6f, 0.8f, 1.0f);
    skyVertices.init();

    float y = Level::HEIGHT + 10.0f;

    for (int x = -1024; x < Level::WIDTH + 1024; x += 512)
    {
        for (int z = -1024; z < Level::DEPTH + 1024; z += 512)
        {
            skyVertices.push(VertexList::Vertex(x, y, z + 512, x / 2048.0f, (z + 512) / 2048.0f, 1.0f));
            skyVertices.push(VertexList::Vertex(x, y, z, x / 2048.0f, z / 2048.0f, 1.0f));
            skyVertices.push(VertexList::Vertex(x + 512, y, z, (x + 512) / 2048.0f, z / 2048.0f, 1.0f));

            skyVertices.push(VertexList::Vertex(x, y, z + 512, x / 2048.0f, (z + 512) / 2048.0f, 1.0f));
            skyVertices.push(VertexList::Vertex(x + 512, y, z, (x + 512) / 2048.0f, z / 2048.0f, 1.0f));
            skyVertices.push(VertexList::Vertex(x + 512, y, z + 512, (x + 512) / 2048.0f, (z + 512) / 2048.0f, 1.0f));
        }
    }

    skyVertices.update();
}

void Skybox::updateWater(unsigned char* waterTextureData)
{
    glBindTexture(GL_TEXTURE_2D, waterTexture);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 16, 16, GL_RGBA, GL_UNSIGNED_BYTE, waterTextureData);
}

void Skybox::renderBedrock()
{
    glBindTexture(GL_TEXTURE_2D, bedrockTexture);
    bedrockVertices.render();
}

void Skybox::renderWater()
{
    glBindTexture(GL_TEXTURE_2D, waterTexture);
    waterVertices.render();
}

void Skybox::renderClouds()
{
    glBindTexture(GL_TEXTURE_2D, cloudsTexture);
    glUniform2f(game.fragmentOffsetUniform, (0.03f * game.timer.ticks) / 2048.f, 0.0f);

    cloudsVertices.render();

    glUniform2f(game.fragmentOffsetUniform, 0.0f, 0.0f);
}

void Skybox::renderSky()
{
    glBindTexture(GL_TEXTURE_2D, skyTexture);
    skyVertices.render();
}
