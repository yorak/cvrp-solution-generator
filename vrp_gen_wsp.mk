.PHONY: clean All

All:
	@echo ----------Building project:[ vrp_gen - Release ]----------
	@"$(MAKE)" -f "vrp_gen.mk"
clean:
	@echo ----------Cleaning project:[ vrp_gen - Release ]----------
	@"$(MAKE)" -f "vrp_gen.mk" clean
