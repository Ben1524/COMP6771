#ifndef GDWG_GRAPH_H
#define GDWG_GRAPH_H

// TODO: Make both graph and edge generic
//       ... this won't just compile
//       straight away

#include <experimental/iterator>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace gdwg
{

    template<typename N, typename E>
    class edge
    {
    public:
        edge(N *source_, N *dest_);

        [[nodiscard]] virtual auto print_node() const -> std::string;

        [[nodiscard]] virtual auto is_weighted() const -> bool = 0;

        auto get_weight() -> std::optional<E>;

        auto get_nodes() const -> std::pair<N, N>;

        virtual ~edge() = default;

        void set_weight(E w);

    private:
        // You may need to add data members and member functions
        N *source;
        N *dest;
        E weight{1};

        template<typename N1, typename E1> friend
        class graph;
    };

email: wy17674094293@163.com
