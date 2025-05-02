#pragma once
class entity_base {};
template<typename... Components>
class entity :public entity_base, public Components...{
    public:
    template<typename ... Args>entity(Args... args) : Components(args)... {}
    entity() = default;
};