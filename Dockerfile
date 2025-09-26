# Стадия сборки
FROM gcc:12.2.0 as builder

WORKDIR /build

# Установка зависимостей для сборки
RUN apt-get update && apt-get install -y make && apt-get clean

COPY Makefile ./
COPY src/ ./src/

# Сборка
RUN make all

# Финальная стадия
FROM gcc:12.2.0

# Установка только runtime зависимостей
RUN apt-get update && apt-get install -y \
    doxygen \
    graphviz \
    && rm -rf /var/lib/apt/lists/* \
    && apt-get clean

WORKDIR /app

# Копируем только собранные бинарники из стадии сборки
COPY --from=builder /build/matrix_calc .
COPY --from=builder /build/matrix_test .

# Создаем пользователя для безопасности
RUN groupadd -r appuser && useradd -r -g appuser appuser
USER appuser

# Точка входа
CMD ["./matrix_test"]