(function ($) {
  Drupal.behaviors.theArkHeaderNavigationPrimary = {
    attach: function () {
      var navigation = $('.header-navigation-primary > .menu')
        , toggle = $('.header-navigation-primary .block__title');
      if (navigation.length === 0 || toggle.length === 0) return;

      toggle.click(function () {
        $('body').toggleClass('body-no-scroll');
        navigation.toggleClass('menu-flyout-visible');
      });
    }
  };
})(jQuery);
