#include "GKrellM.hpp"
#include "ft_gkrellm.hpp"
#include "CPUModule.hpp"

int			main(void)
{
	GKrellM gkrellm;

	gkrellm.loop();
	// CPUModule	q;

	// std::cout << q.getAll() << std::endl;
	return 0;
}
