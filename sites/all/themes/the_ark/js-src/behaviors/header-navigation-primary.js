(function ($) {
  Drupal.behaviors.theArkHeaderNavigationPrimary = {
    attach: function () {
      var navigation = $('.menu-primary-wrapper')
        , toggle = $('.header-navigation-primary .block__title');
      if (navigation.length === 0 || toggle.length === 0) return;

      toggle.click(function () {
        $('body').toggleClass('document-no-scroll');
        toggle.toggleClass('active');
        navigation.toggleClass('menu-flyout-visible');
      });
    }
  };
})(jQuery);
