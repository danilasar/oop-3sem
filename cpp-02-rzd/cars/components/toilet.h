namespace Cars::Components {
    enum ToiletType {
        Invalids,
        Male,
        Female
    };
    class Toilet {
    private:
        ToiletType type;
        bool is_free;
        bool is_working;
    public:
        Toilet(ToiletType type);
        ToiletType GetToiletType();

        bool IsFree();
        bool IsWorking();
        bool IsAvailable();

        void TakeToilet();
        void VacateToilet();

        void OpenToilet();
        void CloseToilet();
        void ToggleToilet();
    };
};
