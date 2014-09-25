(function ($) {
  Drupal.behaviors.theArkHeaderNavigationPrimary = {
    attach: function () {
      var navigation = $('.menu-primary-wrapper')
        , toggle = $('.header-navigation-primary .block__title')
        , buttonClose = $('.menu-primary-close');
      if (navigation.length === 0 || toggle.length === 0 || buttonClose.length === 0) return;

      var toggleClasses = function () {
        $('body').toggleClass('document-no-scroll');
        toggle.toggleClass('active');
        navigation.toggleClass('menu-flyout-visible');
      };

      toggle.bind('tap click', function (event) {
        event.preventDefault();
        if (event.handled === true) return;
        event.handled = true;
        toggleClasses();
      });
      buttonClose.bind('tap click', function (event) {
        event.preventDefault();
        if (event.handled === true) return;
        event.handled = true;
        toggleClasses();
      });

    }
  };
})(jQuery);
