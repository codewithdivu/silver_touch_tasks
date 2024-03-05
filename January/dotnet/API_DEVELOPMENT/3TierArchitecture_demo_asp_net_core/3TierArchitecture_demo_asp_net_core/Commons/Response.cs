namespace _3TierArchitecture_demo_asp_net_core.Commons
{
    public class Response<T>
    {
        public string? Status { get; set; }
        public string? Message { get; set; }
        public T Data { get; set; }
    }
}
